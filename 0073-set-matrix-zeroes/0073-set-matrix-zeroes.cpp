class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int nRows = matrix.size();
        int nCols = matrix[0].size();
        
        vector<int> rowList;
        vector<int> colList;
        
        for (int i = 0; i < nRows; i++) {
            for (int j = 0; j < nCols; j++) {
                if (matrix[i][j] == 0) {
                    rowList.emplace_back(i);
                    colList.emplace_back(j);
                }
            }
        }
        
        for (int i = 0; i < rowList.size(); i++) {
            for (int j = 0; j < nCols; j++) {
                matrix[rowList[i]][j] = 0;
            }
        }
        
        for (int i = 0; i < colList.size(); i++) {
            for (int j = 0; j < nRows; j++) {
                matrix[j][colList[i]] = 0;
            }
        }
    }
};