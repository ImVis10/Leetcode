class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int numRows = grid.size();
        int numCols = grid[0].size();
        int res = 0; 
        
        while (numCols > 0) {
            int eleToAdd = 0;
            for (int i = 0; i < numRows; i++) {
                int maxVal = 0;
                int posToRemove = 0;
                for (int j = 0; j < numCols; j++) {
                    if (grid[i][j] > maxVal) {
                        maxVal = grid[i][j];
                        posToRemove = j;
                    }
                }
                eleToAdd = max(eleToAdd, maxVal);
                grid[i].erase(grid[i].begin() + posToRemove);
            }
            res += eleToAdd;
            numCols--;
        }
        return res;
     }
};