class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return recurse(0, 1, prices, dp);
    }
private:
    int recurse(int idx, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if (idx >= prices.size()) {
            return 0;
        }
        if (dp[idx][buy] != -1) {
            return dp[idx][buy];
        }
        if (buy) {
            return dp[idx][buy] = max(-prices[idx] + recurse(idx + 1, 0, prices, dp), 0 + recurse(idx + 1, 1, prices, dp));
        }
        return dp[idx][buy] = max(prices[idx] + recurse(idx + 2, 1, prices, dp), 0 + recurse(idx + 1, 0, prices, dp));
    }
    
    // GETTING TLE SO GOTTA USE A CACHE
};