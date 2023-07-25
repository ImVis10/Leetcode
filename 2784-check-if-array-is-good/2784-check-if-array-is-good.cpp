class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());
        
        if (n != maxVal + 1) return false;
        
        bool isGood = true;
        unordered_map<int, int> map;
        for (auto& num : nums) {
            map[num] += 1;
            if (map[num] > 1 && num != maxVal || map[num] > 2 && num == maxVal) {
                isGood = false;
            }
        }
        return isGood;
    }
};