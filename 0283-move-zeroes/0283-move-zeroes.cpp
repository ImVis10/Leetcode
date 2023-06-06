class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        
        int i = 0, j = 0;
        
        for (i = 0; i < n; i ++) {
            if (nums[i] != 0) {
                if (j < i) {
                    nums[j] = nums[i];
                    nums[i] = 0;
                }
                j++;
             }
        }
    }
};