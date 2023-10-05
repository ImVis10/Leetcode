class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        
        for (int num : nums) {
            map[num]++;
        }
        
        int target = nums.size() / 3;
        
        vector<int> res;
        
        for (auto&[k, v] : map) {
            if (v > target) res.push_back(k);
        }
        
        return res;
    }
};