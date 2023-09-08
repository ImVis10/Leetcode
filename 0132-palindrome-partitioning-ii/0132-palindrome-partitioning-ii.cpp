class Solution {
public:
    int minCut(string s) {        
        vector<int> cache(s.length(), -1);
        
        // precompute palindrome check.. doing this because of MLE and TLE
        vector<vector<bool>> isPalindrome(s.length(), vector<bool>(s.length(), false));
        precomputePalindromeCheck(s, isPalindrome);
        
        int minCuts = recurse(0, s, cache, isPalindrome);
        return minCuts - 1;
    }
private:
    int recurse(int idx, string s, vector<int>& cache, const vector<vector<bool>>& isPalindrome) {
        if (idx == s.length()) {
            return 0;
        }
        
        if (cache[idx] != -1) {
            return cache[idx];
        }
        
        int minCuts = INT_MAX;
        
        for (int i = idx; i < s.length(); i++) {
            if (isPalindrome[idx][i]) {
                int cuts = 1 + recurse(i + 1, s, cache, isPalindrome);
                minCuts = min(cuts, minCuts);
            }
        }
        
        return cache[idx] = minCuts;
    }
    
    void precomputePalindromeCheck(string s, vector<vector<bool>> &isPalindrome) {
        int n = s.length();

        // Every character is a palindrome by itself
        for (int i = 0; i < n; i++) {
            isPalindrome[i][i] = true;
        }

        // Check for two-character palindromes
        for (int i = 0; i < n - 1; i++) {
            isPalindrome[i][i + 1] = (s[i] == s[i + 1]);
        }

        // Check for longer palindromes
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                isPalindrome[i][j] = (s[i] == s[j] && isPalindrome[i + 1][j - 1]);
            }
        }
    }
};