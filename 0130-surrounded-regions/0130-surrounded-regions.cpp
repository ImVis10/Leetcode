class Solution {
    vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int row = 0; row < m; row++) {
            dfs(row, 0, board, visited);
            dfs(row, n - 1, board, visited);
        }
        
        for (int col = 0; col < n; col++) {
            dfs(0, col, board, visited);
            dfs(m-1, col, board, visited);
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) board[i][j] = 'X';
            }
        }  
    }
private:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<bool>>& visited) {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || visited[row][col] || board[row][col] != 'O') {
            return;
        }
        
        visited[row][col] = true;
        
        for (auto& d : dir) {
            int rowTo = row + d[0];
            int colTo = col + d[1];
            dfs(rowTo, colTo, board, visited);
        }
    }
};