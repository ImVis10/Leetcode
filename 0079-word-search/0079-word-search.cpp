class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();
        // set<pair<int, int>> visited; // not using set as search time in set is leading to TLE
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (recurse(i, j, board, 0, word)) {
                    return true;
                }
            }
        }
        return false;
    }
    
private:
    bool recurse(int row, int col, vector<vector<char>>& board, int idx, string word) {
        if (idx == word.length()) {
            return true;
        }
        
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] != word[idx] || board[row][col] == 'v') {
            return false;
        }
        
        char beforeVisit = board[row][col];
        board[row][col] = 'v'; // visited
        bool res = recurse(row + 1, col, board, idx + 1, word) ||
                   recurse(row - 1, col, board, idx + 1, word) ||
                   recurse(row, col + 1, board, idx + 1, word) ||
                   recurse(row, col - 1, board, idx + 1, word);
        board[row][col] = beforeVisit; // backtrack, if this doesn't result in a successful search in the current path, it might result in a successful search in a different path. So remove the element from the visited set for the current path.
        return res;
    }
};