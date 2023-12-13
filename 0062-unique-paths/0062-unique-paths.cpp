class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> cache(m, vector<int> (n, -1));
        return recurse(0, 0, m, n, cache);
    }
private:
    int recurse(int i, int j, int m, int n, vector<vector<int>>& cache) {
        if (i== m - 1 and j == n - 1) return 1;
        if (i > m - 1 or j > n - 1) return 0;
        if (cache[i][j] != -1) return cache[i][j];
        
        int right = recurse(i, j + 1, m, n, cache);
        int down = recurse(i + 1, j, m, n, cache);
        
        return cache[i][j] = right + down;
    }
};