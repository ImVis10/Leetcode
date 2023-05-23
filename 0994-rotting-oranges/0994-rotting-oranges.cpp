class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int time = 0, fresh = 0;
        
        int nRows = grid.size();
        int nCols = grid[0].size();
        
        for (int i = 0; i < nRows; i++) {
            for (int j = 0; j < nCols; j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                } else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        
        
        
        while (!q.empty() && fresh > 0) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto cell = q.front();
                q.pop();
                for (int d = 0; d < dirs.size(); d++) {
                    int toRow = dirs[d][0] + cell.first;
                    int toCol = dirs[d][1] + cell.second;
                    if (toRow < 0 || toRow >= nRows || toCol < 0 || toCol >= nCols ||grid[toRow][toCol] != 1) {
                        continue;
                    }
                    grid[toRow][toCol] = 2;
                    q.push({toRow, toCol});
                    fresh--;
                }
            }
            time++;
        }
        return fresh == 0 ? time : -1;
    }
private:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};