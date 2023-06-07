class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        int count = 0;
        int sum = 0;
        
        map<int, int> prefixSumCount;
        prefixSumCount[0] = 1;
        
        // Until an index 'i' say sum = x, so to figure out no. of subarrays that sum to K, it is better to figure out no. of prefix subarrays that sum to 'x - k' as finding prefix sum is easier than finding between sum.
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int remove = sum - k;
            count += prefixSumCount[remove];
            prefixSumCount[sum] += 1;
        }
        return count;
    }
};