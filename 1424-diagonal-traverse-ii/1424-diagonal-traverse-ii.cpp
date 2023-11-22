class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
//         unordered_map<int, vector<int>> mp;
//         int maxSumOfIndices = 0;
        
//         for (int i = nums.size() - 1; i >= 0; i--) {
//             for (int j = 0; j < nums[i].size(); j++) {
//                 mp[i + j].push_back(nums[i][j]);
//                 maxSumOfIndices = max(i + j, maxSumOfIndices);
//             }
//         }
        
//         vector<int> res;
//         for (int i = 0; i <= maxSumOfIndices; i++) {
//             for (int num : mp[i]) res.push_back(num);
//         }
//         return res;
        // FROM SOLUTION SECTION - USING BFS, SINGLE PASS
        queue<pair<int, int>> q;
        q.push({0, 0});
        
        vector<int> res;
        
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            res.push_back(nums[row][col]);
            
            if (col == 0 && row + 1 < nums.size()) q.push({row + 1, col});
            if (col + 1 < nums[row].size()) q.push({row, col + 1});
        }
        return res;
    }
};