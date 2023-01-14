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
            
/**When the total stays +ve, we don't do anything to the start point, our start pointer points to the first index when our total became positive.

suppose we start from X(-ve)--->Y(-ve)--->A(+ve)---->B(+ve)---->C(+ve), where C is the end of the array, our start(which is also the ans) would be A.

Why not B? why not C?
It is because we moved from A to B with some +ve value or atleast 0, whereas if we started from B we would have had only the value of B so earlier point added some value to our total, so its more favorable to help us reach the ans, hence earliest point is always better.

Why we just stop at point C and don t complete the cycle and check?
It is because if we arrived till here it means that there is an answer and it is unique, so we will always choose the most favorable answer which is also the fundamental idea of Greedy Algorithims.**/
            
            if (total < 0) {
                total = 0;
                start = i + 1;
            }
        }
        
        return start;
    }
};