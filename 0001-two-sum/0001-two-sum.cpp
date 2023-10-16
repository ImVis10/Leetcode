class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;
        
        for (int i = 0; i < n; i++) {
            int firstNum = nums[i];
            int secondNum = target - firstNum;
            if (mp.find(secondNum) != mp.end()) return {mp[secondNum], i};
            mp[firstNum] = i;
        }
        return {};
    }
};