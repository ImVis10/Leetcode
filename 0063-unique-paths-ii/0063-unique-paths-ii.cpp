class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> cache(m, vector<int> (n, -1));
        return recurse(0, 0, m, n, cache, obstacleGrid);
    }
private:
    int recurse(int i, int j, int m, int n, vector<vector<int>>& cache, vector<vector<int>>& grid) {
        if (i == m - 1 and j == n - 1 and grid[i][j] == 0) return 1;
        if (i > m - 1 or j > n - 1 or grid[i][j] == 1) return 0;
        if (cache[i][j] != -1) return cache[i][j];
        
        int right = recurse(i, j + 1, m, n, cache, grid);
        int down = recurse(i + 1, j, m, n, cache, grid);
        
        return cache[i][j] = right + down;
    }
};