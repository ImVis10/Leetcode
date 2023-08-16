class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> cache(m, vector<int>(n , -1));
        return recurse(0, 0, m - 1, n - 1, obstacleGrid, cache);
    }
private:
    int recurse(int currRow, int currCol, int destRow, int destCol, vector<vector<int>>& grid, vector<vector<int>>& cache) {
        if (currRow < destRow + 1 && currCol < destCol + 1 && grid[currRow][currCol] == 1) return 0;

        if (currRow == destRow && currCol == destCol) return 1;
        if (currRow > destRow || currCol  > destCol) return 0;
        
        
        if (cache[currRow][currCol] != -1) return cache[currRow][currCol];
        
        int down = recurse(currRow + 1, currCol, destRow, destCol, grid, cache);
        int right = recurse(currRow, currCol + 1, destRow, destCol, grid, cache);
        
        return cache[currRow][currCol] = down + right;
    }
};