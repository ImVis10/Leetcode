class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int maxProfit = 0;
        
        int buy = 0, sell = 1;
        
        while (sell < prices.size()) {
            if (prices[sell] > prices[buy]) {
                int profit = prices[sell] - prices[buy];
                maxProfit = max(profit, maxProfit);          
            } else {
                buy = sell;
            }
            sell++;
        }
        return maxProfit;
    }
};