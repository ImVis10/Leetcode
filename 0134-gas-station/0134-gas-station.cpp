class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalGas = 0, totalCost = 0;
        
        // if the sum of gas is less than the total cost, it means that there is not enough gas to make the round trip. The cost is higher than the amount of gas available to make a round trip
        if (accumulate(gas.begin(), gas.end(), totalGas) < accumulate(cost.begin(), cost.end(), totalCost)) {
            return -1;
        }
        
        int total = 0;
        int start = 0;
        
        for (int i = 0; i < n; i++) {
            total += gas[i] - cost[i];
            
            if (total < 0) {
                total = 0;
                start = i + 1;
            }
        }
        return start;
    }
};