class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n); // board of n rows
        string s(n, '.'); // each row has n cols
        for (int i = 0; i < n; i++) {
            board[i] = s; // init config of chess board. All empty
        }
        recurse(0, board, res, n);
        return res;
    }
private:
    void recurse(int col, vector<string>& board, vector<vector<string>>& res, int n) {
        if (col == n) { // if we cross the last col 'n - 1', it means that N-Queens is solved.
            res.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (cantAttackExistingQueens(row, col, board, n)) {
                board[row][col] = 'Q';
                recurse(col + 1, board, res, n);
                board[row][col] = '.'; // backtrack
            }
        }
    }
    
    bool cantAttackExistingQueens(int row, int col, vector<string> board, int n) {
        int rowStore = row, colStore = col;
        
        while (row >= 0 && col >= 0) { // upward left
            if (board[row][col] == 'Q') return false;
                row--;
                col--;
        }
        
        row = rowStore, col = colStore;
        while (col >= 0) { // left
            if (board[row][col] == 'Q') return false;
            col--;
        }
        
        col = colStore;
        while (row < n && col >= 0) { // downward left
            if (board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        // no need to check in other directions as if a queen is in current col, it'll be the only queen in that col for now, so mo need to move up and down. There won't be any queens present towards the right cols at the moment. So only check towards the left i.e. left, upward left, downward left.
        return true;
    }
};