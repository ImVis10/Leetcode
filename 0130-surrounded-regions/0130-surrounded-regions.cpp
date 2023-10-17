class Solution {
    vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        
        for (int row = 0; row < m; row++) {
            dfs(row, 0, board);
            dfs(row, n - 1, board);
        }
        
        for (int col = 0; col < n; col++) {
            dfs(0, col, board);
            dfs(m-1, col, board);
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'D') board[i][j] = 'O';
            }
        }  
    }
private:
    void dfs(int row, int col, vector<vector<char>>& board) {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != 'O') {
            return;
        }
        
        board[row][col] = 'D';
        
        for (auto& d : dir) {
            int rowTo = row + d[0];
            int colTo = col + d[1];
            dfs(rowTo, colTo, board);
        }
    }
};