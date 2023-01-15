class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        // we have to buy at local minima and sell at local maxima
        for (int i = 1;  i < prices.size(); i++) {
            // we buy before and sell after
            if (prices[i] > prices[i - 1]) { // if selling price is greater than buying price
                profit += (prices[i] - prices[i-1]);
            }
        }
        return profit;
    }
};