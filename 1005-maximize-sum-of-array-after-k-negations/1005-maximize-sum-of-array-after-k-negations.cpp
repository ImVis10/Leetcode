class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        // sort the array
        // apply the modification for once on the smallest element
        // sort again
        // apply the modifiction again on the smallest element
        // sort again
        // repeat for k times
        
        
        while (k > 0) {
            sort(nums.begin(), nums.end());
            nums[0] = -nums[0];
            k--;
        }
        
        return accumulate(nums.begin(), nums.end(), 0);
        
    }
};