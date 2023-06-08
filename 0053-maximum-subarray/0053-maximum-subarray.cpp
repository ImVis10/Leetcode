class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Kadane's algorithm
        // Don't move forward with negative sum coz its better to start with new one as our objective is to maximize the sum of the subarray 
        int maxSum = INT_MIN;
        int sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            maxSum = max(sum, maxSum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return maxSum;
    }
};