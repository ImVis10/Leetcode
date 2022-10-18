class Solution {
    public int searchInsert(int[] nums, int target) {
        if(nums == null || nums.length == 0) {
            return 0;
        }
        int n = nums.length;
        int start = 0;
        int end = n - 1;
        while(start <=  end) {
            int mid = start + (end - start) / 2;
            if(nums[mid] == target) { // if target is found
                return mid;
            } else if(nums[mid] < target) { // if target is greater than mid element, search from mid + 1
                start = mid + 1;
            } else { // if target is less than mid element, search only till mid - 1
                end = mid - 1;
            }
        }
        return start; // return when search space is reduced to 1.
    }
}