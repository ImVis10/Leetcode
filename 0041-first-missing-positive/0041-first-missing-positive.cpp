class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // for an array of size n, the solution set would be in the range [1, 2, ... , n + 1]
        // eg: [1,2,3,5] --> res = 4 which is in the range [1,2,3,4,5]
        // eg: [3,4,-1,1] --> res = 2 which is in the range [1,2,3,4,5]
        // eg : [1,2,0] --> res = 3 which is in the range [1,2,3,4]
        // eg: [1,2,3] --> res = 4 which is in the range [1,2,3,4]
        
        // Previously I used O(n) extra space to solve this (set). Now solving this using constant extra space.
        // Mutating the input array to indicate the elements present in the array
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0) { // we actually have no use with non-positive numbers
                nums[i] = n + 2; // so changing them to a value which can't be the solution (len(nums) + 2) so that no conflict arises while finding the actual result
            }
        }
        
        for (int  i = 0; i < n; i++) {
            if (abs(nums[i]) <= n && nums[abs(nums[i]) - 1] > 0) {
                nums[abs(nums[i]) - 1] *= -1; // a -ve value indicates that 'i' is present in the input array
                // Detailed : a -ve value indicates that the the abs(value next to it) is present in the array
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        
        return n + 1;
    }
};