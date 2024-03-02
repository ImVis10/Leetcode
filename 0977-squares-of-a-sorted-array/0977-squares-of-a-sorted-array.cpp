class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        /** So the idea is magnitude of 1st element might be greater than the magnitude to last element
        so we compare both of those first
        1. If abs(nums[0]) > abs(nums[n-1]) we set res[n-1] = nums[0] ^ 2, and we move the low pointer one step ahead
        2. If abs(nums[0]) < abs(nums[n-1]) we set res[n-1] = nums[n-1] ^ 2, and we move the high pointer one step back
        **/
        int n = nums.size();
        int low = 0, high = n - 1;
        vector<int> res(n);
        for (int i = n - 1; i >= 0; i--) {
            if (abs(nums[low]) > abs(nums[high])) {
                res[i] = nums[low] * nums[low];
                low++;
            } else {
                res[i] = nums[high] * nums[high];
                high--;
            }
        }
        return res;
    }
};