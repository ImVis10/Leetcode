class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (m > 0 and nums[m - 1] > nums[m]) {
                r = m - 1;
            } else if (m < n - 1 and nums[m + 1] > nums[m]) {
                l = m + 1;
            } else {
                return m;
            }
        }
        return -1;
    }
};