class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int profit = 0;
        // // we have to buy at local minima and sell at local maxima
        // for (int i = 1;  i < prices.size(); i++) {
        //     // we buy before and sell after
        //     if (prices[i] > prices[i - 1]) { // if selling price is greater than buying price
        //         profit += (prices[i] - prices[i-1]);
        //     }
        // }
        // return profit;
        
        // The above solution eventhough intuitive is incorrect in someways (I guess)
        // For the example below, eventhough the solution is correct we do a lot of transactions
        // prices = [1,2,3,4,5]
        // with the above solution, buy 1st day sell 2nd day, buy 2nd day sell 3rd day.. so on
        // But if you see in the explanation we should buy on 1st sell on last day.. only one transaction
        
        int profit = 0, days = prices.size();
        int buy = 0, sell = 0;
        
        while (buy < days && sell < days) {
            while (buy < days - 2 && prices[buy + 1] < prices[buy]) { // buy at valleys
                buy++;
            }
            
            sell = buy;
            
            while(sell < days - 1 && prices[sell + 1] > prices[sell]) { // sell at peaks
                sell++;
            }
            
            profit += (prices[sell] - prices[buy]);
            
            buy = sell + 1;
        }
        return profit;
    }
};