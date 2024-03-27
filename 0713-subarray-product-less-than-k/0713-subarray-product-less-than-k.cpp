class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int n = nums.size(), res = 0, product = 1;
        for (int i = 0, j = 0; j < n; j++) {
            product *= nums[j];
            while (product >= k) {
                product /= nums[i++];
            }
            res += j - i + 1;
        }
        return res < 0 ? 0 : res;
    }
};