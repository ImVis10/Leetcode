class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int numZeros = 0;
        int res = 0; // window size
        
        int start = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            numZeros += nums[i] == 0;
            if (numZeros > 1) {
                numZeros -= (nums[start] == 0);
                start++;
            }
            res = max(res, i - start);
        }
        return res;
    }
};