class Solution {
public:
    int countHomogenous(string s) {
        int n = s.length();
        long long mod = 1e9 + 7;
        long long res = 0;
        
        // SLIDING WINDOW
        for (int start = 0, end = 0; end < n; end++) {
            if (end > 0 && s[end] != s[end - 1]) {
                start = end;
            }
            res += end - start + 1;
            res %= mod;
            
        }
        return (int) res;
    }
};