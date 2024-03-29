class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(), sum = 0, res = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for (int i = 0; i < n; i++) {
            sum += nums[i] == 1 ? 1 : -1;
            if (mp.find(sum) != mp.end()) {
                res = max(res, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }
        return res;
    }
};