class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    res++;
                    dfs(i, j, grid, visited);
                }
            }
        }
        return res;
    }
private:
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        visited[row][col] = true;
        
        vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        
        for (int i = 0; i < 4; i++) {
            int rowTo = row + dir[i][0];
            int colTo = col + dir[i][1];
            
            if (rowTo >= 0 && rowTo < grid.size() && colTo >= 0 && colTo < grid[0].size() && !visited[rowTo][colTo] && grid[rowTo][colTo] == '1') {
                dfs(rowTo, colTo, grid, visited);
            }
        }
    }
};