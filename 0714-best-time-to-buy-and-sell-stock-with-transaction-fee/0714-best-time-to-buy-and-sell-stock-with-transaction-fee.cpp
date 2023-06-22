class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // NOT STRONG ENOUGH IN DP YET.. TOOK FROM SOLUTION SECTION
        // engage in a transaction only if the profit - free is >= 0
        // DP - dp[i] represents maximum profit on day 'i'
        // Suppose, to sell a stock on a day, we must hold the stock in the first place. But there is a chance that we might not have bought the stock to sell it.
        // So on a day 'd' we might be holding the stock or we might not be holding the stock
        // So two dp arrays are needed, one when holding the stock (hold) and when not holding the stock (notHold) to represent maximum profit on a certain day
        int n = prices.size();
        vector<int> hold(n , 0);
        vector<int> notHold(n, 0);
        
        hold[0] -= prices[0];
        
        for (int i = 1; i < n; i++) {
            hold[i] = max(hold[i - 1], notHold[i - 1] - prices[i]);
            notHold[i] = max(notHold[i - 1], hold[i - 1] + prices[i] - fee); 
        }
        return notHold[n - 1]; // returning notHold as we should not have any stocks with us at the end of n days
    }
};