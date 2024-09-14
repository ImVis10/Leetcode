class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), cnt = 0, res = 0, maxVal = 0;
        for (int num : nums) {
            if (num > maxVal) {
                maxVal = num;
                cnt = res = 0; // doing this coz we only know the max so far
            }
            cnt = num == maxVal ? cnt + 1 : 0;
            res = max(res, cnt);
        }
        return res;
    }
};