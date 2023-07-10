// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int n = nums.size();
//         int currSum = 0;
//         for (int i = 0, j = 0; j < n; j++) { // i--> start of the window, j--> end of the window
//             currSum += nums[j];
            
//             while (currSum - nums[i] > )
//         }
//     }
// };

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int res = INT_MAX;
        int prefixSum = 0;
        for (int i = 0, j = 0; j < n; j++) {
            prefixSum += nums[j];
            while (prefixSum >= target) {
                res = min(res, j - i + 1);
                prefixSum -= nums[i++];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
