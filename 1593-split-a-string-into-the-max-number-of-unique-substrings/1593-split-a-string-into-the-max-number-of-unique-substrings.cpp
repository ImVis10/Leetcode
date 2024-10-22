class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> set;
        return backtrack(s, 0, set);
    }
private:
    int backtrack(string& s, int idx, unordered_set<string>& set) {
        if (idx == s.size()) return 0;
        int maxSplits = 0;
        for (int i = idx; i < s.size(); i++) {
            string substr = s.substr(idx, i - idx + 1);
            if (set.find(substr) == set.end()) {
                set.insert(substr);
                int splits = 1 + backtrack(s, i + 1, set);
                set.erase(substr);
                maxSplits = max(splits, maxSplits);
            }
        }
        return maxSplits;
    }
};