class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        // I suppose it's a DP problem
        // To find the longest 'ARITHMETIC' subsequence that has the given difference
        // We need maximum length of subsequence ending at each number
        /** TWO choices at each step
        1. To choose the number --> we choose the number if it is a part of arithmetic progression with the given difference
        If we have an element with value 'arr[i] - difference', we can include arr[i] in the subsequence.
        2. To not choose the number --> we don't choose the number if it is not of a part of AP
        If we don't have an element with value 'arr[i] - difference', we will start new subsequence from arr[i]
        
        But since we're dealing with length of subsequence here, the DP equation would be:
        dp[arr[i]] = max(dp[arr[i] - difference], res) (res is init to be 1)
        
        Since we need to check for the presence of element arr[i] - difference, we will use a map
        **/
        
        unordered_map<int, int> dp;
        
        int res = 1;
        
        for (auto& num : arr) {
            if (dp.count(num - difference)) dp[num] = dp[num - difference] + 1;
            else dp[num] = 1;
            res = max(res, dp[num]);
        }
        return res;
    }
};