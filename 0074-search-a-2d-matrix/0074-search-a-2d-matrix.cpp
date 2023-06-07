class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // each row is sorted in non decreasing order
        // so can do binary search, to find out the row
        
        int numRows = matrix.size(), numCols = matrix[0].size();
        int topRow = 0, bottomRow = numRows - 1;
        int currRow = 0;
        
        // finding out the row
        while (topRow <= bottomRow) {
            currRow = topRow + (bottomRow - topRow) / 2;
            if (target > matrix[currRow][numCols - 1]) {
                topRow = currRow + 1;
            } else if (target < matrix[currRow][0]) {
                bottomRow = currRow - 1;
            } else { // this might be the row
                break;
            }
        }
        
        
        // check if the element is present in the row
        int low = 0, high = numCols - 1;
        int targetRow = currRow;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (target == matrix[targetRow][mid]) {
                return true;
            } else if (target > matrix[targetRow][mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
};