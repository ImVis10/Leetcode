class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < n; i++) {
            map[nums[i]].push_back(i);
        }
        
        vector<int> maxKeys;
        int maxCount = 0;
        int res = INT_MAX;
        
        for(auto& pair : map) {
            if (pair.second.size() > maxCount) {
                maxCount = pair.second.size();
            }
        }
        
        for (auto& pair : map) {
            if (pair.second.size() == maxCount) {
                if (pair.second.size() == 1) return 1;
                res = min(res, pair.second[maxCount - 1] - pair.second[0] + 1);
            }
        }
        
        return res;
    }
};