class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<string, bool> cache;
        return recurse(s, dict, cache);
    }
private:
    bool recurse(string s, unordered_set<string> dict, unordered_map<string, bool>& cache) {
        if (cache.count(s)) {
            return cache[s];
        }
        if (s.length() == 0) { // when we get an empty string, it might mean that we're at the end of the string and the words have been matched.
            return true;
        }
        for (int i = 0; i < s.length(); i++) {
            if (dict.count(s.substr(0, i + 1)) && recurse(s.substr(i + 1), dict, cache)) {
                cache[s] = true;
                return true;
            }
        }
        cache[s] = false;
        return false;
    }
};

// GETTING TLE AS I'M MAKING A LOT OF RECURSIVE CALLS FOR WHICH RESULT IS ALREADY KNOWN. THESE CAN BE REDUCED BY USING A CACHE THAT CAN STORE THOSE RESULTS.