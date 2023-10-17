class Solution {
    vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        int fresh = 0;
        
        queue<pair<int, int>> q;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) fresh++;
                else if (grid[i][j] == 2) q.push({i, j}); 
            }
        }
        int time = bfs(grid, fresh, q);
        return time;
    }
private:
    int bfs(vector<vector<int>>& grid, int fresh, queue<pair<int, int>>& q) {
        int m = grid.size(), n = grid[0].size();
        int time = 0;
        while (!q.empty() && fresh) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) { //  for every minute check for oranges that get sick
                auto cell = q.front();
                q.pop();
                for (auto& dir : dirs) {
                    int rowTo = cell.first + dir[0];
                    int colTo = cell.second + dir[1];
                    if (rowTo < 0 || rowTo >= m || colTo < 0 || colTo >= n || grid[rowTo][colTo] != 1) continue;
                    grid[rowTo][colTo] = 2;
                    q.push({rowTo, colTo});
                    fresh--;
                }
            }
            time++;
        }
        return fresh == 0 ? time : -1;
    }
};