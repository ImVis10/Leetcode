class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res;
        int m = mat.size(), n = mat[0].size(), currRow = 0, currCol = 0;
        bool up  = true;
        
        while (currRow < m and currCol < n) {
            if (up) {
                while (currRow > 0 and currCol < n - 1) {
                    res.push_back(mat[currRow--][currCol++]);
                }
                res.push_back(mat[currRow][currCol]);
                if (currCol == n - 1) currRow++;
                else currCol++;
            } else {
                while (currRow < m - 1  and currCol > 0) {
                    res.push_back(mat[currRow++][currCol--]);
                }
                res.push_back(mat[currRow][currCol]);
                if (currRow == m - 1) currCol++;
                else currRow++;
            }
            up = !up;
        }
        return res;
    }
};