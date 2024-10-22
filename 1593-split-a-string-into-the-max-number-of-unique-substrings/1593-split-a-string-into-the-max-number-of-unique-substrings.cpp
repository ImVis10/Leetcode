class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> set;
        int maxSplits = 0;
        backtrack(s, 0, set, 0, maxSplits);
        return maxSplits;
    }
private:
    void backtrack(string& s, int start, unordered_set<string>& set, int splits, int& maxSplits) {
        if (splits + (s.size() - start) <= maxSplits) return;
        if (start == s.size()) {
            maxSplits = max(maxSplits, splits);
            return;
        }
        for (int end = start + 1; end <= s.size(); end++) {
            string substr = s.substr(start, end - start);
            if (set.find(substr) == set.end()) {
                set.insert(substr);
                backtrack(s, end, set, splits + 1, maxSplits);
                set.erase(substr);
            }
        }
    }
};