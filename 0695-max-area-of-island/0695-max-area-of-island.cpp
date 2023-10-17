class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        int res = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                   res =  max(res, dfs(i, j, grid, visited));
                }
            }
        }
        return res;
    }
private:
    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        visited[row][col] = true;
        
        vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        
        int area = 1;
        
        for (int i = 0; i < dir.size(); i++) {
            int rowTo = row + dir[i][0];
            int colTo = col + dir[i][1];
            if (rowTo >= 0 && rowTo < grid.size() && colTo >= 0 && colTo < grid[0].size() && grid[rowTo][colTo] == 1 && !visited[rowTo][colTo]) {
                area += dfs(rowTo, colTo, grid, visited);
            }
        }
        return area;
    }
};