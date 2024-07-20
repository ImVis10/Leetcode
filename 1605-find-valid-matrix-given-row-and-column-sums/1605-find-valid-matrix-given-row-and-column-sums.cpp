class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        // GREEDY
        
        // THE CONSTRAINT SUM(ROWSUM) == SUM(COLSUM) IS THE KEY HERE
        // R1 + R2 + R3 + .... == C1 + C2 + C3 + ...
        // TAKE THE MIN(Ri, Cj) AND PLACE IT AT res[i][j]
        // NOW THE ABOVE EQUATION BECOMES, SAY R1 IS MINIMUM
        // (r1 - r1) + r2 + r3 + .. == (c1 - r1) + c2 + c3 +....
        
        int m = rowSum.size(), n = colSum.size();
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= res[i][j];
                colSum[j] -= res[i][j];
            }
        }
        return res;
    }
};