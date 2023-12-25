class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        
        int right = n - 1, bottom = m - 1, left = 0, top = 0;
        int idx = 0;
        
        vector<int> spiral(m * n);
        
        while (left <= right and top <= bottom) {
            for (int col = left; col <= right; col++) {
                spiral[idx++] = matrix[top][col];
            }
            top++;
            for (int row = top; row <= bottom; row++) {
                spiral[idx++] = matrix[row][right];
            }
            right--;
            if (top <= bottom) {
                for (int col = right; col >= left; col--) {
                    spiral[idx++] = matrix[bottom][col];
                }   
            }
            bottom--;
            if (left <= right) {
                for (int row = bottom; row >= top; row--) {
                    spiral[idx++] = matrix[row][left];
                }
            }
            left++;
        }
        return spiral;
    }
};