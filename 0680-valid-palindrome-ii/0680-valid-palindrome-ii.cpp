class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.length();
        if (n <= 2) return true;
        int i = 0, j = n - 1;

        while (i < j) {
          if (s[i] != s[j]) {
            return isPalin(s, i, j - 1) or isPalin(s, i + 1, j);
          }
          i++;
          j--;
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