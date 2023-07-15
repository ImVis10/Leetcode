class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // int prefixSum = 0;
        // unordered_map<int, int> map({{0, 1}});
        // int res = 0;
        // for (auto& num : nums) {
        //     prefixSum += num;
        //     res += map[prefixSum - goal];
        //     map[prefixSum]++;
        // }
        // return res;
        
        // USING SLIDING WINDOW
        return helper(nums, goal) - helper(nums, goal - 1);
        
    }
private: 
    int helper(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        int res = 0;
        int n = nums.size(), sum = 0;
        
        for (int i = 0, j = 0; j < n; j++) {
            sum += nums[j];
            while (sum > goal) {
                sum -= nums[i++];
            }
            res += j - i + 1;
        }
        return res;
    }
};