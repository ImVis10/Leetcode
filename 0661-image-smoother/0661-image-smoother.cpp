class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                int sum = 0, cnt = 0;
                for (int i = row - 1; i <= row + 1; i++) {
                    for (int j = col - 1; j <= col + 1; j++) {
                        if (i < 0 or i >= m or j < 0 or j >= n) continue;
                        sum += img[i][j];
                        cnt += 1;
                    }
                }
                res[row][col] = sum / cnt;
            }
        }
        return res;
    }
 };