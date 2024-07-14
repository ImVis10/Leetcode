class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles, empty = numBottles, full = 0;
        while (empty >= numExchange) {
            full = empty / numExchange;
            res += full;
            empty = full + (empty % numExchange);
        }
        return res;
    }
};