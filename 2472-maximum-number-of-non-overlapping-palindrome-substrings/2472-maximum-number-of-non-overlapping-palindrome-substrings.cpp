class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length(), res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int len = j - i + 1;
                // to maximize the # of palindromes, we gotta minimize the length of palindromes
                if (len > k + 1) break;
                if (len >= k and isPalin(s, i, j)) {
                    res++;
                    i = j;
                    break;
                }
            }
        }
        return res;
    }
private:
    bool isPalin(string& s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }
};