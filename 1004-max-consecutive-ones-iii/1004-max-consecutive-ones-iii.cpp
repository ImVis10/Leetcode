class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // so return the longest subarray with atmost k 0s, as the array is binary in nature
        // In example given: nums= [1,1,1,0,0,0,1,1,1,1,0], k = 2
        // this would be subarray from [5 to n - 1]
        int n = nums.size(), count = 0;
        int res = 0;
        for (int i = 0, j = 0; j < n; j++) {
            if (nums[j] == 0) count++;
            while (count > k) {
                if (nums[i++] == 0) count--;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};