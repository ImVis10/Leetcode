class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> palin;
        recurse(0, s, palin, res);
        return res;
    }
private:
    void recurse(int idx, string s, vector<string> palin, vector<vector<string>>& res) {
        if (idx == s.length()) {
            res.push_back(palin);
            return;
        }
        for (int i = idx; i < s.length(); i++) {
            if (isPalin(s, idx, i)) {
                palin.push_back(s.substr(idx, i - idx + 1)); // cpp substr is not the same as java subString(). In cpp, first parameter is the start position and second parameter is not the end position but the length of the substring.
                recurse(i + 1, s, palin, res);
                palin.pop_back();
            }
        }
    }
    
    bool isPalin(string s, int left, int right) {
        while (left <= right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }
};