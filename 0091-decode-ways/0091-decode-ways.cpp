class Solution {
public:
    int numDecodings(string s) {
        // to be a valid char, the value must be atmost 2 chars
        // 1st digit either 1 or 2, if 1, 2nd digit can be anything
        // if 2, 2nd digit is in the range 0 to 6
        // no digit should start with 0
        int n = s.length();
        
        if (s[0] == '0') return 0;
        
        vector<int> dp(n + 1); // dp[i] represents the number of ways to decode the substring s[0...i-1]
        dp[0] = 1;
        dp[1] = 1;
        
        for (int i = 2; i < n + 1; i++) {
            int ones = stoi(s.substr(i - 1, 1));
            // dp[i - 1] is used because when we find a valid one-digit number, we want to know how many ways there were to decode the string up to that point, excluding this one digit
            if (ones >= 1) dp[i] += dp[i - 1];
            int tens = stoi(s.substr(i - 2, 2)); 
            // dp[i - 2] is used because when we find a valid two-digit number, we want to know how many ways there were to decode the string up to that point, excluding these two digits
            if (tens >= 10 and tens <= 26) dp[i] += dp[i - 2];
        }
        return dp[n];
    }
};