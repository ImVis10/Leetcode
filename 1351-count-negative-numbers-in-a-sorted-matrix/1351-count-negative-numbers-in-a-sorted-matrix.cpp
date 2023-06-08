class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        // each row is sorted in non-increasing order
        // so can use BINARY SEARCH
        
        int numRows = grid.size(), numCols = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < numRows; i++) {
            int firstOccurencePosofNegativeNumber = getFirstOccuredPosOfNegativeNumber(grid[i], 0, numCols - 1, 0);
            if (firstOccurencePosofNegativeNumber != -1) {
                cnt += numCols - firstOccurencePosofNegativeNumber;
            }
        }
        return cnt;
    }
private:
    int getFirstOccuredPosOfNegativeNumber(vector<int> row, int low, int high, int target) {
        while (low <= high) {
            int mid = (low + high) / 2;
            if ((mid == 0 || row[mid - 1] >= 0) && row[mid] < target) {
                return mid;
            } else if (target > row[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1; 
            }
        }
        return -1;
    }
};