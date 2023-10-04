class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> map;
        
        for (int num : nums) { // update count
            map[num]++;
        }
        
        int res = 0;
        
        for (auto&[k, v] : map) {
            res += v * (v - 1) / 2;
        }
        
        return res;
    }
};