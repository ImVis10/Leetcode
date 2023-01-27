class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int res = 0, count = 0;
        sort(costs.begin(), costs.end());
        for(int cost : costs) {
            if (res + cost <= coins) {
                res += cost;
                count++;
            } 
        }
        return count;
    }
};