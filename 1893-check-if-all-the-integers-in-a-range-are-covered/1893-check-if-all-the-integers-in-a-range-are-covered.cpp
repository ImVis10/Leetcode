class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        unordered_map<int, int> map;
        
        for (auto range : ranges) {
            for (int num = range[0]; num <= range[1]; num++) {
                map[num]++;
            }
        }
        
        for (int num = left; num <= right; num++) {
            if (!map.count(num)) {
                return false;
            }
        }
        
        return true;
    }
};