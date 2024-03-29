class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size();
        int m = worker.size();
        int res= 0;
        
        // To reduce time and space complexity
        int maxDifficulty = *max_element(difficulty.begin(), difficulty.end());
        int maxAbility = *max_element(worker.begin(), worker.end());
        
        int maxLevel = max(maxDifficulty, maxAbility);
        
        vector<int> arr(maxLevel + 1, 0);

        
        // make a map of difficulty (key) --> profit (value)
        for (int i = 0; i < n; i++) {
            arr[difficulty[i]] = max(profit[i], arr[difficulty[i]]); // to take the max profit when there is duplicate difficulty
        }
        
        int maxProfit = 0;
        
        // Idea is that a task with difficulty 'd' can be taken upon by a worker with ability >= d, and work on maximum profit tasks
        // eg: a task with difficulty '3' can be taken upon a worker with ability 4, 5, 6...
        // set the maximum profit attainable at each difficulty
        for (int i = 0; i <= maxLevel; i++) {
            maxProfit = max(maxProfit, arr[i]);
            arr[i] = maxProfit;
        }
        
        for (int i = 0; i < m; i++) {
            res += arr[worker[i]];
        }
        return res;
    }
};