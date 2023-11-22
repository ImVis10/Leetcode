class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> mp;
        int maxSumOfIndices = 0;
        
        for (int i = nums.size() - 1; i >= 0; i--) {
            for (int j = 0; j < nums[i].size(); j++) {
                mp[i + j].push_back(nums[i][j]);
                maxSumOfIndices = max(i + j, maxSumOfIndices);
            }
        }
        
        vector<int> res;
        for (int i = 0; i <= maxSumOfIndices; i++) {
            for (int num : mp[i]) res.push_back(num);
        }
        return res;
    }
};