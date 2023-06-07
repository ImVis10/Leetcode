class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0, sell = 1;
        int res = 0;
        while (sell < prices.size()) {
            if (prices[sell] > prices[buy]) {
                int profit = prices[sell] - prices[buy];
                res = max(res, profit);
            } else { // if a lower price to buy is found, buy at that
                buy = sell;
            }
            sell++;
        }
        return res;
    }
};