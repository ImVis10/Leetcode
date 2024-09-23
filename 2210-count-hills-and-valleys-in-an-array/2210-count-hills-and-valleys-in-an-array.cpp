class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for (int curr = 1, prev = 0; curr < n - 1; curr++) {
            if ((nums[curr] > nums[prev] and nums[curr] > nums[curr + 1]) or (nums[curr] < nums[prev] and nums[curr] < nums[curr + 1])) {
                res++;
                prev = curr;
            }
        }
        return res;
    }
};