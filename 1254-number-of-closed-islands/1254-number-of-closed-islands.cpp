class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        // 1 - water
        // 0 - land
        int res = 0;
        
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<bool>> visited(row, vector<bool>(col));
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 0 && !visited[i][j] && dfs(i, j, row, col, grid, visited)) {
                    res++;
                }
            }
        }
        return res;
    }
    
    // dfs to know whether the cell is a closed island or not
    bool dfs(int currRow, int currCol, int nRows, int nCols, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        if (currRow < 0 || currCol < 0 || currRow >= nRows || currCol >= nCols) {
            return false;
        }
        
        if (grid[currRow][currCol] == 1 || visited[currRow][currCol]) {
            return true;
        }
        
        visited[currRow][currCol] = true;
        bool isClosed = true;
        
        vector<int> row {0, -1, 0, 1};
        vector<int> col {-1, 0, 1, 0};
        
        for (int i = 0; i < 4; i++) {
            if (!dfs(currRow + row[i], currCol + col[i], nRows, nCols, grid, visited)) {
                isClosed = false;
            }
        }
        
        return isClosed;
    }
};