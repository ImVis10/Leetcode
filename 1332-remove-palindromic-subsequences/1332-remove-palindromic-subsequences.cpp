class Solution {
public:
    int removePalindromeSub(string s) {
        if (s.empty()) return 0;
        int n = s.length();
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            if (s[i] != s[j]) return 2;
        }
        return 1;
    }
};