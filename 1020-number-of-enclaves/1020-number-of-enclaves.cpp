class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int res = 0;
        
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<bool>> visited(row, vector<bool>(col));
        
        // check at 4 boundaries for land cells and start dfs from them
        for (int i = 0; i < row; i++) {
            if (grid[i][0] == 1 && !visited[i][0]) { // left column
                dfs(i, 0, row, col, grid, visited);   
            }
            
            if (grid[i][col - 1] == 1 && !visited[i][col - 1]) { // right column
                dfs(i, col - 1, row, col, grid, visited);
            }
        }
        
        for (int i = 0; i < col; i++) {
            if (grid[0][i] == 1 && !visited[0][i]) { // top row
                dfs(0, i, row, col, grid, visited);
            }
            
            if (grid[row - 1][i] == 1 && !visited[row - 1][i]) { // bottom row
                dfs(row - 1, i, row, col, grid, visited);
            }
        }
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    res++;
                }
            }
        }
        return res;
    }
    
private:
    void dfs(int currRow, int currCol, int nRows, int nCols, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        if (currRow < 0 || currCol < 0 || currRow >= nRows || currCol >= nCols || grid[currRow][currCol] == 0 || visited[currRow][currCol]) {
            return;
        }
        
        visited[currRow][currCol] = true;
        
        vector<int> row {0, -1, 0, 1};
        vector<int> col {-1, 0, 1, 0};
        
        for (int i = 0; i < 4; i++) {
            dfs(currRow + row[i], currCol + col[i], nRows, nCols, grid, visited);
        }
    }
};