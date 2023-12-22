class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, vector<int>> mp;
        
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        int maxFreq = 0, res = INT_MAX;
        
        for (auto& entry : mp) {
            if (entry.second.size() > maxFreq) maxFreq = entry.second.size();
        }
                
        for (auto& entry : mp) {
            if (entry.second.size() == maxFreq) {
                res = min(res, entry.second[maxFreq - 1] - entry.second[0] + 1);
            }
        }
        return res;
    }
};