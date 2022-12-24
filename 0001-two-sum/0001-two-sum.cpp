class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        unordered_map<int, int> map;
        for (int i = 0; i < len; i++) {
            int secondNum = target - nums[i];
            if (map.find(secondNum) != map.end()) { // if the element is already in the map
                return {map[secondNum], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};