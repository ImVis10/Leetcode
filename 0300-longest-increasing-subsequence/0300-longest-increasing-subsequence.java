class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int[] lis = new int[n];
        int res = 0;
        
        Arrays.fill(lis, 1);
        
        for(int i = 1 ; i < n ; i++) {
            for(int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
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