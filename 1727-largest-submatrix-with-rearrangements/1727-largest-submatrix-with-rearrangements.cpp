class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        
        int res = 0;
        
        vector<int> heights(n);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) heights[j] = 0;
                else heights[j]++;
            }
            vector<int> temp = heights;
            sort(temp.begin(), temp.end());
            for (int curr = 0; curr < n; curr++) {
                res = max(res, temp[curr] * (n - curr)); // width is n - curr because smaller height can be extended till the end, say height at curr = 1, it is sure that height would be >= 1 until the end, so height of 1 can be extended unitl n - 'i'
            }
        }        
        return res;
    }
};