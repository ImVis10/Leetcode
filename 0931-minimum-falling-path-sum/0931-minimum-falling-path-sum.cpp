class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> cache(n, vector<int>(n, -101));
        int minPath = INT_MAX;
        for (int col = 0; col < n; col++) {
            minPath = min(minPath, recurse(n - 1, col, matrix, cache));
        }
        return minPath;
    }
private:
    int recurse(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& cache) {
        if (col < 0 || col > grid.size() - 1) return 1e9;
        if (row == 0) return grid[row][col];
        if (cache[row][col] != -101) return cache[row][col];
        
        int leftDiag = grid[row][col] + recurse(row -1, col - 1, grid, cache);
        int up = grid[row][col] + recurse(row - 1, col, grid, cache);
        int rightDiag = grid[row][col] + recurse(row -1, col + 1, grid, cache);
        
        return cache[row][col] = min({leftDiag, up, rightDiag});
    }
};