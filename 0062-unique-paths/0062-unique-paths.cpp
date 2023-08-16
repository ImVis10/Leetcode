class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> cache(m, vector<int>(n + 1 , -1));
        return recurse(0, 0, m - 1, n - 1, cache);
    }
private:
    int recurse(int currRow, int currCol, int destRow, int destCol, vector<vector<int>>& cache) {
        if (currRow == destRow && currCol == destCol) return 1;
        if (currRow > destRow || currCol  > destCol) return 0;
        
        if (cache[currRow][currCol] != -1) return cache[currRow][currCol];
        
        int down = recurse(currRow + 1, currCol, destRow, destCol, cache);
        int right = recurse(currRow, currCol + 1, destRow, destCol, cache);
        
        return cache[currRow][currCol] = down + right;
    }
};