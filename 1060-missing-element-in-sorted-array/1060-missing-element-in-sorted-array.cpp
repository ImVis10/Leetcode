class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();
        int low = nums[0], high = nums[n - 1];
        for (int i = 1; i < n; i++) {
            while (nums[i] != ++low) {
                if (--k == 0) {
                    return low;
                }
            }
        }
        return nums[n - 1] + k;
    }
};