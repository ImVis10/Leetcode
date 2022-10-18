class Solution {
    public int pivotIndex(int[] nums) {
        int sum = 0, totalSum = 0;
        int len = nums.length;
        int []sumUntilThatIndex = new int[len];
        for (int  i = 0; i < len ; i++) {
            totalSum += nums[i];
        }
        for (int i = 1; i < len ; i++) {
            sum += nums[i - 1];
            sumUntilThatIndex[i] = sum;
        }
        
        for (int i = 0; i < len; i++) {
            int leftSum = sumUntilThatIndex[i];
            int rightSum = totalSum - sumUntilThatIndex[i] - nums[i];
            if (leftSum == rightSum) {
                return i;
            }
        }
        return -1;
    }
}