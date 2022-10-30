class Solution {
    public void moveZeroes(int[] nums) {
        int p1 = 0, p2 = 0; // p2 for storing the index of the zeroes that are on the left side of a non-zero number.
        int n = nums.length;
        // Just try swap for each and every iteration. But it is asked to minimize the number of operations done.
        // So avoid unnecessary swaps. Swap only when there are zeroes on the left side of a non-zero number.
        for (p1 = 0; p1 < n; p1++) {
            if (nums[p1] != 0) {
                if (p2 < p1) {
                    nums[p2] = nums[p1];
                    nums[p1] = 0;
                }
                p2++;
            }
        }
    }
}