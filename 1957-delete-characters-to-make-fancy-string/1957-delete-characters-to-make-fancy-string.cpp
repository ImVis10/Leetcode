class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        if (n <= 2) return s;
        string res;
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == s[i - 1] and s[i] == s[i + 1]) continue;
            res += s[i];
        }
        return s[0] + res + s[n - 1];
    }
};