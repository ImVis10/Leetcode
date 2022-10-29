class Solution {
    public void rotate(int[] nums, int k) {
        int len = nums.length;
        k = k % len; // as k can be greater than the length of the array and effectively number of different results can only upto length of the array. So 'mod'ing k with len. To avoid index out of the bounds exception as well.
        reverseArray(nums, 0, len - 1);
        reverseArray(nums, 0, k - 1);
        reverseArray(nums, k , len - 1);
        
    }
    
    private void reverseArray(int[] nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
}