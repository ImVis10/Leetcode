class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int[] lis = new int[n];
        int res = 0;
        
        Arrays.fill(lis, 1);
        
        for(int i = n - 2 ; i >= 0 ; i--) {
            for(int j = i + 1; j < n; j++) {
                if (nums[i] < nums[j]) {
                    lis[i] = Math.max(lis[i], lis[j] + 1);
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            if (lis[i] > res) {
                res = lis[i];
            }
        }
        
        return res;
        
    }
}