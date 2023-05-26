class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int nRows = matrix.size();
        
        // interchange row and column of each element in the matrix
        for (int i = 0; i < nRows; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // reverse each row
        for (int i = 0; i < nRows; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};