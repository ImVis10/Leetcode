class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        // valid subarrays must contain both minK and maxK
        // and must not contain any element out of range [minK, maxK]
        
        // No mood and energy to think at the moment. So directly taking a peek at the solution.
        
        // Focus on each index i and count the number of valid subarrays that end at i
        
        // We need to record 3 indices
        // 1. leftBound: index of the most recent value out of range [minK, maxK]
        // 2. maxPos: index of the most recent value == maxK
        // 3. minPos: index of the most recent value == minK
        
        long long res = 0;
        
        int minPos = -1, maxPos = -1, leftBound = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < minK || nums[i] > maxK) leftBound = i;
            if (nums[i] == minK) minPos = i;
            if (nums[i] == maxK) maxPos = i;
            // min(minPos, maxPos) - leftBound gives no. of valid subarrays ending at i
            // but if leftBound is to the right of the min(minPos, maxPos) which means that there is no valid subarray ending at i.
            // so take a max(0, min(minPos, maxPos) - leftBound)
            res += max(0, min(minPos, maxPos) - leftBound);
        }
        return res;
    }
};