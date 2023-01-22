class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // we can reach the stair 'i' in two ways:
        // 1 step from i - 1 or 2 steps from i - 2
        vector<int> res(cost.size() + 1);
        
        for (int i = 2; i < res.size(); i++) {
            int oneStep = res[i - 1] + cost[i - 1];
            int twoStep = res[i - 2] + cost[i - 2];
            res[i] = min(oneStep, twoStep);
        }
        return res[res.size() - 1];
    }
};