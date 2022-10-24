class Solution {
    public int maxProfit(int[] prices) {
        int leastPriceSoFar = Integer.MAX_VALUE;
        int profit = 0;
        int profitIfSoldToday = 0;
        
        for(int i = 0; i < prices.length; i++) {
            if(prices[i] < leastPriceSoFar) {
                leastPriceSoFar = prices[i];
            }
            profitIfSoldToday = prices[i] - leastPriceSoFar;
            if(profit < profitIfSoldToday) {
                profit = profitIfSoldToday;
            }
        }
        return profit;
    }
}