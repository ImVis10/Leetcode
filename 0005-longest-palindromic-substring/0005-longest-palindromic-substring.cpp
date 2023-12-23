class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        
        vector<vector<bool>> cache(n, vector<bool>(n));
        
        int maxLen = 0, start = 0;
        
        string res = "";
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                cache[i][j] = s[i] == s[j] && (j - i < 3 || cache[i + 1][j - 1]);
                
                if (cache[i][j] && j - i + 1 > maxLen) {
                    start = i;
                    maxLen = j - i + 1;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};