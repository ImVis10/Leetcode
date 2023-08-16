class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> cache(m, vector<int>(n + 1 , -1));
        return recurse(m - 1, n - 1, cache);
    }
private:
    int recurse(int row, int col, vector<vector<int>>& cache) {
        if (row == 0 && col == 0) return 1;
        if (row < 0 || col < 0) return 0;
        
        if (cache[row][col] != -1) return cache[row][col];
        
        int up = recurse(row - 1, col, cache);
        int left = recurse(row, col - 1, cache);
        
        return cache[row][col] = up + left;
    }
};