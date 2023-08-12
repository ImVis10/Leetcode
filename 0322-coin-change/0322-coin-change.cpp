class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // get the minimum number of coins needed for each amount from '1' to amount.
        // so we need to store the previous results so that it can be used to calculate the next ones.
        vector<long> dp(amount + 1, INT_MAX); // bcoz 0-indexing
        dp[0] = 0;
        
        for (int i = 1; i <= amount; i++) {
            for (auto coin : coins) {
                if (i - coin >= 0) { // if we can use the 'coin' for the current amount 'i'
                    // we can take as many coins as possible. But let's try to keep it to minimum
                    dp[i] = min(dp[i], dp[i - coin] + 1); // why dp[i - coin] + 1? we gotta make an amount of 'i', so it can be made with (i - coin) + coin, so how many ways 'i - coin' can be made and +1 for using coin  
                }
            }
        }        
        return dp[amount] != INT_MAX ? dp[amount] : -1;
    }
};