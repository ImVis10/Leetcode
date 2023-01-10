class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // can use binary search on each of the rows
        // each row --> O(log n), m rows --> m log n
        // But solution should be found in O(log mn) --> log m + log n
        // So first figure out which row the target is in O(log m) using binary search
        //
        int numRows = matrix.size(), numCols = matrix[0].size();
        
        int topRow = 0, bottomRow = numRows - 1;
        int currRow = 0;
        
        while (topRow <= bottomRow) {
            currRow = topRow + (bottomRow - topRow) / 2;
            if (matrix[currRow][0] > target) {
                bottomRow = currRow - 1; 
            } else if (matrix[currRow][numCols - 1] < target) {
                topRow = currRow + 1;
            } else {
                break;
            }
        }
        
        if (topRow > bottomRow) return false;
        
        int low = 0, high = numCols - 1;
        int targetRow = currRow; 
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (matrix[targetRow][mid] > target) {
                high = mid - 1;
            } else if (matrix[targetRow][mid] < target) {
                low = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};