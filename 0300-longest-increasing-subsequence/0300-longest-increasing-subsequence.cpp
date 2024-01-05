class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), res = 0;
        vector<int> lis(n, 1); // lis[i] represents the the length of Longest Increasing Subsequence that starts at i, the minum guarenteed value is 1
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] < nums[j]) lis[i] = max(lis[i], lis[j] + 1);
            }
        }
        
        for (int val : lis) {
            if (val > res) res = val;
        }
        return res;
    }
};