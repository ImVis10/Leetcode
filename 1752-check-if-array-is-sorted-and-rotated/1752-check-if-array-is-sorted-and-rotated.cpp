class Solution {
public:
    bool check(vector<int>& nums) {
        
        int flag = 1;
        
        int n = nums.size();
        
        int minBeforeBreakPoint = nums[0];
        int maxBeforeBreakPoint = -1;
        int breakPoint = -1;
        int maxAfterBreakPoint = -1;
        
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) { // dipping point
                flag = 0;
                maxBeforeBreakPoint = nums[i];
                breakPoint = i + 1;
                break;
            }
        }
        
        if (flag == 1) { // if the array is already sorted
            return true;
        }
        
        for (int i = breakPoint; i < n - 1; i++) {
            if (nums[i] <= nums[i + 1]) {
                maxAfterBreakPoint = nums[i + 1];
            } else { // if the sub-array after the dipping point is not sorted
                return false;
            }
        }
        
        if (breakPoint == n - 1) { // if the dipping point is at the last element of the array
            maxAfterBreakPoint = nums[breakPoint];
        }
        return maxAfterBreakPoint <= minBeforeBreakPoint;
    }
};