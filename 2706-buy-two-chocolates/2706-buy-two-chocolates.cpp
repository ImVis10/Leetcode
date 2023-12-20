class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int cheapest = INT_MAX, secondCheapest = INT_MAX;
        
        for (int price : prices) {
            if (price < cheapest) {
                secondCheapest = cheapest;
                cheapest = price;
            } else {
                secondCheapest = min(secondCheapest, price);
            }
        }
        int cost = cheapest + secondCheapest;
        return cost > money ? money : money - cost;
    }
};