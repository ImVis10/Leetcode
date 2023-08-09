class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
//         sort(nums.begin(), nums.end());
//         vector<vector<int>>dp (nums.size(), vector<int>(p + 1, -1));
//         return recurse(0, nums, p, dp);
//     }
// private:
//     int recurse(int idx, vector<int>& nums, int p, vector<vector<int>>& dp) {
//         if (p == 0) {
//             return 0;
//         }
        
//         if (idx >= nums.size() - 1) {
//             return INT_MAX;
//         }
        
//         if (dp[idx][p] != -1) {
//             return dp[idx][p];
//         }
//         return dp[idx][p] = min(max(abs(nums[idx] - nums[idx + 1]), recurse(idx + 2, nums, p - 1, dp)), recurse(idx + 1, nums, p, dp)); // choose or not choose a certain index
        
        // GETTING MLE. SO GOTTA DO BINARY SEARCH ON ANSWER (SAW THE RELATED TOPICS TAG)
        if (p == 0) return 0;
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int low = 0, high = 1e9;
        int res = 1e9;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canBeTheAnswer(mid, p, nums)) {
                res = mid;
                high = mid - 1; // check if the answer can be still lower 
            } else {
                low = mid + 1;
            }
        }
        return res;
    }
private:
    bool canBeTheAnswer(int currentAnswer, int p, vector<int>& nums) {
        int idx = 0;
        
        while (idx < nums.size() - 1) {
            if (abs(nums[idx] - nums[idx + 1]) <= currentAnswer) {
                idx += 2; // pick, so move to next to next index as we can't use the same index more than once
                p -= 1;
            } else {
                idx += 1; // not pick, so move to next index
            }

            if (p == 0) {
                return 1;
            }
        }
        return 0;
    }
};