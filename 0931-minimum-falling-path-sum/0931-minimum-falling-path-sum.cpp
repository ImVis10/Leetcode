class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> cache(n, vector<int> (n, -101));
        int minPath = INT_MAX;
        for (int col = 0; col < n; col++) {
            minPath = min(minPath, recurse(0, col, matrix, cache));
        }
        return minPath;
    }
private:
    int recurse(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& cache) {
        if (col < 0 or col >= matrix.size()) return 1e9;
        if (row == matrix.size() - 1) return matrix[row][col];
        if (cache[row][col] != -101) return cache[row][col];
        
        int leftDiagnol = matrix[row][col] + recurse(row + 1, col - 1, matrix, cache);
        int down = matrix[row][col] + recurse(row + 1, col, matrix, cache);
        int rightDiagnol = matrix[row][col] + recurse(row + 1, col + 1, matrix, cache);
        
        return cache[row][col] = min(leftDiagnol, min(down, rightDiagnol));
    }
};