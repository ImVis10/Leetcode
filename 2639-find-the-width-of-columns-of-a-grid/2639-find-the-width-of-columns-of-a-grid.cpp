class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> res(n, -1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int currLen = to_string(grid[j][i]).length();
                res[i] = max(res[i], currLen);
            }
        }
        return res;
    }
};