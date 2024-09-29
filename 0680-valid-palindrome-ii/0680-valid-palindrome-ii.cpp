class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.length();
        if (n <= 2) return true;
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1]) {
                return isPalin(s, i, n - i - 2) or isPalin(s, i + 1, n - i - 1);
            }
        }
        return true;
    }
private:
    bool isPalin(string s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
};