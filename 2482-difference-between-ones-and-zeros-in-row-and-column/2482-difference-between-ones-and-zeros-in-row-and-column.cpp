class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<int> onesRow(m), onesCol(n);
        vector<vector<int>> diff(m, vector<int>(n));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                onesRow[i] += grid[i][j];
                onesCol[j] += grid[i][j];
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                diff[i][j] = (onesRow[i] + onesCol[j]) - ((n - onesRow[i]) + (m - onesCol[j]));
            }
        }
        return diff;
    }
};