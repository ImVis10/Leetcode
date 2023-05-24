class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int nRows = matrix.size();
        int nCols = matrix[0].size();
        
        int col0 = 1;
        
        for (int i = 0; i < nRows; i++) {
            for (int j = 0; j < nCols; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    
                    if (j != 0) {
                        matrix[0][j] = 0;
                    } else {
                        col0 = 0;
                    }
                }
            }
        }
        
        for (int i = 1; i < nRows; i++) {
            for (int j = 1; j < nCols; j++) {
                if (matrix[i][j] != 0) {
                    if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        
        if (matrix[0][0] == 0) {
            for (int j = 0; j < nCols; j++) {
                matrix[0][j] = 0;
            }
        }
        
        if (col0 == 0) {
            for (int i = 0; i < nRows; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};