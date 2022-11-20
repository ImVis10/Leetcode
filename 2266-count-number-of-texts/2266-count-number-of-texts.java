class Solution {
    public int countTexts(String pressedKeys) {
        // Let's solve with an example of '222'
        /**can be viewed as following:
            _'22' --> 1 way as 2 can in prefix can only mean a
            __'2' --> 2 ways as 22 in prefix can be mean aa or b
            '222' --> 1 way i.e. c
            **/
        int mod = 1000000007;
        
        int n = pressedKeys.length();
        int[] dp = new int[n + 1];
        dp[0] = 1; // empty string can be represented in 1 way only
        
        for (int i = 0; i < n; i++) {
            int numLetters = 3;
            char c = pressedKeys.charAt(i);
            if (c == '7' || c == '9') {
                numLetters = 4;
            }
            
            dp[i + 1] = dp[i]; // pressing the key once --> 1st '2' is presssed
            
            for (int j = 0; j < numLetters - 1; j++) {
                if (i - j - 1 >= 0 && pressedKeys.charAt(i) == pressedKeys.charAt(i - j - 1)) {
                    dp[i + 1] += dp[i - j - 1];
                } else {
                    break;
                }
                dp[i + 1] %= mod;
            }
        }
        
        return dp[n];
    }
}