class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), lastNonZeroAt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[lastNonZeroAt++] = nums[i];
            }
        }
        while (lastNonZeroAt < n) {
            nums[lastNonZeroAt++] = 0;
        }
    }
};