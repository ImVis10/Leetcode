class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int maxRowMin = INT_MIN, minColMax = INT_MAX;
        for (int i = 0; i < m; i++) {
            int rowMin = INT_MAX;
            for (int j = 0; j < n; j++) {
                rowMin = min(rowMin, matrix[i][j]);
            }
            maxRowMin = max(rowMin, maxRowMin);
        }
        for (int i = 0; i < n; i++) {
            int colMax = INT_MIN;
            for (int j = 0; j < m; j++) {
                colMax = max(colMax, matrix[j][i]);
            }
            minColMax = min(colMax, minColMax);
        }
        // return maxRowMin != minColMax ? {} : {maxRowMin}; CAN'T SEEM TO USE TERNARY HERE error: initializer list cannot be used on the right hand side of operator '?'
        if (maxRowMin != minColMax) return {};
        return {maxRowMin};
    }
};