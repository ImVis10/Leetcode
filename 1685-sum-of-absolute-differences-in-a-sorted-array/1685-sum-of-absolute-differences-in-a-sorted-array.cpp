class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        
        /**
        res[i] = |nums[i] - nums[0]| + |nums[i] - nums[1]| + .... + |nums[i] - nums[i - 1]| + 0 + |nums[i] - nums[i + 1]| + .... + |nums[i] - nums[n - i - 1]|
        res[i] = (nums[i] - nums[0]) + .... + (nums[i] - nums[i - 1]) + .... + (nums[i + 1] - nums[i]) + .... + (nums[n - 1] - nums[i]);
        res[i] = (i * nums[i]) - (nums[0] + nums[1] + .... + nums[i - 1]) + (nums[i + 1] + nums[i + 2] + .... + nums[n - 1]) - (n - i - 1 * nums[i])
        res[i] = (i * nums[i] - prefixSum[i]) + (postfixSum[i] - (n - i - 1) * nums[i])
        **/
        
        vector<int> prefixSum(n);
        vector<int> postfixSum(n);
        
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }
        
        for (int i = n - 2; i >= 0; i--) {
            postfixSum[i] = postfixSum[i + 1] + nums[i + 1];
        }
        
        vector<int> res(n);
        
        for (int i = 0; i < n; i++) {
            res[i] = (i * nums[i] - prefixSum[i]) + (postfixSum[i] - (n - i - 1) * nums[i]);
        }
        return res;
    }
};