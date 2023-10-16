class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> grid1D = convert2DTo1D(grid);
        vector<int> res1D = productExceptSelf(grid1D);
        vector<vector<int>> res2D = convert1DTo2D(res1D, m, n);
        return res2D;
        
    }
private:
    vector<int> convert2DTo1D(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> res(m * n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i * n + j] = grid[i][j];
            }
        }
        return res;
    }
    
    vector<vector<int>> convert1DTo2D(vector<int>& grid, int m, int n) {
        vector<vector<int>> res(m, vector<int>(n));
        int gridSize = m * n;
        for (int i = 0; i < gridSize; i++) {
            int row = i / n;
            int col = i % n;
            res[row][col] = grid[i];
        }
        return res;
    }
    
    vector<int> productExceptSelf(vector<int>& grid) {
        int n = grid.size();
        int prodBefore = 1, prodAfter = 1;
        vector<int> res(n , 1);
        
        for (int i = 1; i < n; i++) {
            prodBefore = (prodBefore * (grid[i - 1] % 12345)) % 12345;
            res[i] = prodBefore;
        }
        
        for (int i = n - 2; i >= 0; i--) {
            prodAfter = (prodAfter * (grid[i + 1] % 12345)) % 12345;
            res[i] = (res[i] * prodAfter) % 12345;
        }
        
        return res;
    }
};