class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int prefixSum = 0;
        unordered_map<int, int> map({{0, 1}});
        int res = 0;
        for (auto& num : nums) {
            prefixSum += num;
            res += map[prefixSum - goal];
            map[prefixSum]++;
        }
        return res;
    }
};