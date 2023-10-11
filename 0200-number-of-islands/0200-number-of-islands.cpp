class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        int res = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    res++;
                    bfs(i, j, visited, grid);
                }
            }
        }
        return res;
    }
    
private:
    void bfs(int row, int col, vector<vector<bool>>& visited, vector<vector<char>>& grid) {
        visited[row][col] = true;
        queue<pair<int, int>> q;
        q.push({row, col});
        
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            // push the neighbors onto the queue
            vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
            for (int i = 0; i < dir.size(); i++) {
                int neighRow = row + dir[i][0];
                int neighCol = col + dir[i][1];
                if (neighRow >= 0 && neighRow < grid.size() && neighCol >= 0 && neighCol < grid[0].size() && grid[neighRow][neighCol] == '1' && !visited[neighRow][neighCol]) {
                    visited[neighRow][neighCol] = true;
                    q.push({neighRow, neighCol});
                }
            }
            
        }
    }
};