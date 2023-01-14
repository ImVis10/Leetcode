class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // start with the station which has enough gas to travel to next station
        // so gas[i] > cost[i]
        int n = gas.size();
        int totalGas = 0, totalCost = 0;
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