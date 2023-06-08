class Solution {
// public:
//     int countNegatives(vector<vector<int>>& grid) {
//         // each row is sorted in non-increasing order
//         // so can use BINARY SEARCH
        
//         int numRows = grid.size(), numCols = grid[0].size();
//         int cnt = 0;
//         for (int i = 0; i < numRows; i++) {
//             int firstOccurencePosofNegativeNumber = getFirstOccuredPosOfNegativeNumber(grid[i], 0, numCols - 1, 0);
//             if (firstOccurencePosofNegativeNumber != -1) {
//                 cnt += numCols - firstOccurencePosofNegativeNumber;
//             }
//         }
//         return cnt;
//     }
// private:
//     int getFirstOccuredPosOfNegativeNumber(vector<int> row, int low, int high, int target) {
//         while (low <= high) {
//             int mid = (low + high) / 2;
//             if ((mid == 0 || row[mid - 1] >= 0) && row[mid] < target) {
//                 return mid;
//             } else if (target > row[mid]) {
//                 high = mid - 1;
//             } else {
//                 low = mid + 1; 
//             }
//         }
//         return -1;
//     }
    
    // OPTIMAL APPROACH - FROM SOLUTION SECTION O(m + n)
    // Approach is based on the statement that the matrix is sorted in decreasing order both rowwise and columnwise
    // https://imgur.com/a/pxJUp8j
    // As the array is also sorted columnwise, a negative number in a row 'i + 1' can't be at an index after the negative number in a row 'i'
public :
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        int n = grid[0].size();
        int currRowFirstNegativeStartAfter = n - 1; // index of the last postive number in a row
        
        for (auto row : grid) {
            while (currRowFirstNegativeStartAfter >= 0 && row[currRowFirstNegativeStartAfter] < 0) {
                currRowFirstNegativeStartAfter--;
            }
            cnt += (n - (currRowFirstNegativeStartAfter + 1));
        }
        return cnt;
    }
};