class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int numRows = matrix.size();
        int numCols = matrix[0].size();
        
        // Transpose the matrix
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // Reverse each row
        for (int i = 0; i < numRows; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};