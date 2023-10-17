class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // to check 3 things
        // 1. if the row is valid
        // 2. if the column is valid
        // 3. if the sub squares are valid
        
        for (int i = 0; i < 9; i++) {
            bool rowCheck = isRowValid(board, i);
            if (!rowCheck) return false;
            
            bool colCheck = isColumnValid(board, i);
            if (!colCheck) return false;
            
            bool subSquareCheck = isSubSquareValid(board, i);
            if (!subSquareCheck) return false;
        }
        return true;
    }
private:
    bool isRowValid(vector<vector<char>>& board, int row) {
        set<char> st;
        for (char ch : board[row]) {
            if (ch != '.') {
                if (st.find(ch) != st.end()) return false;
                st.insert(ch);
            }
        }
        return true;
    }
    
    bool isColumnValid(vector<vector<char>>& board, int col) {
        set<char> st;
        for (int i = 0; i < 9; i++) {
            char ch = board[i][col];
            if (ch != '.') {
                if (st.find(ch) != st.end()) return false;
                st.insert(ch);
            }
        }
        return true;
    }
    
    bool isSubSquareValid(vector<vector<char>>& board, int box) {
        set<char> st;
        
        int startRow = (box / 3) * 3;
        int startCol = (box % 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                char ch = board[startRow + i][startCol + j];
                if (ch != '.') {
                    if (st.find(ch) != st.end()) return false;
                    st.insert(ch);
                }
            }
        }
        return true;
    }
};