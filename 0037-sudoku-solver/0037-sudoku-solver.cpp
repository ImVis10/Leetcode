class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        recurse(board);
    }
private:
    bool recurse(vector<vector<char>>& board) {
        int rows = board.size(), cols = board[0].size();
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isSafe(board, i, j, c)) {
                            board[i][j] = c;
                            if (recurse(board)) {
                                return true;
                            } else {
                                board[i][j] = '.'; // restore to previous state i.e. backtrack.
                            }
                        }
                    }
                    return false; // if all c's returned unsafe
                }
            }
        }
        return true; // if no more empty cells it means that sudoku is solved. So return true.
    }
    
    bool isSafe(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c) { // row check
                return false;
            }
            
            if (board[i][col] == c) { // col check
                return false;
            }
            
            if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == c) {
                return false;
            }
        }
        return true;
    }
};