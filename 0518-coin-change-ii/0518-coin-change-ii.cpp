class Solution {
public:
    int change(int amount, vector<int>& coins) {
//         return recurse(coins.size() - 1, amount, coins);
//     }
// private:
//     int recurse(int idx, int target, vector<int>& coins) {
//         if (idx == 0) {
//             return (target % coins[idx] == 0);
//         }
        
//         int noPick = recurse(idx - 1, target, coins);
//         int pick = 0;
//         if (coins[idx] <= target) {
//             pick = recurse(idx, target - coins[idx], coins);
//         }
//         return pick + noPick; 
//     }
        
        // GETTING TLE AS THE TIME COMPLEXITY IS O (target) and lot of overlapping sub problems which should not be computed multiple no. of times
        // so gotta memoize this
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return recurse(coins.size() - 1, amount, coins, dp);
    }
private:
    int recurse(int idx, int target, vector<int>& coins, vector<vector<int>>& dp) {
        if (idx == 0) {
            return (target % coins[idx] == 0);
        }
        
        if (dp[idx][target] != -1) {
            return dp[idx][target];
        }
        
        int noPick = recurse(idx - 1, target, coins, dp);
        int pick = 0;
        if (coins[idx] <= target) {
            pick = recurse(idx, target - coins[idx], coins, dp);
        }
        return dp[idx][target] = pick + noPick;
    }
    
};