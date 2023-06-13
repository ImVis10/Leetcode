class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int numRows = grid.size();
        int numCols = numRows;
        
        int cnt = 0;
        
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                bool isEqual = true;
                
                for (int k = 0; k < numRows; k++) {
                    if (grid[i][k] != grid[k][j]) {
                        isEqual = false;
                        break;
                    }
                }
                
                cnt += isEqual ? 1 : 0;
            }
        }
        return cnt;
    }
};