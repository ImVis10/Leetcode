// KEY IDEA: VISUALIZE THIS AS FLOOD FROM OCEAN. DONT TRY TO DO OTHER WAY AROUND AS IT WILL COMPLICATE THINGS, DOING DFS FROM EVERY CELL, AND WE WILL BE DOING A LOT OF REDUNDANT OPERATIONS I.E., GOING THROUGH THE SAME PATHS, ALSO KNOWING WHEN TO STOP THE FLOOD WOULD ALSO BE DIFFICULT, CHECKING IF WE'VE REACHED THE EDGE OF THE MATRIX OR IF WE'VE ALREADY VISITED A PARTICULAR CELL
// IF THE FLOOD FROM BOTH THE OCEANS REACH THE NODE, ADD IT TO THE RESULT SET
class Solution {
    vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        
        vector<vector<bool>> floodFromPacific(m, vector<bool>(n, false));
        vector<vector<bool>> floodFromAtlantic(m, vector<bool>(n, false));
        
        for (int row = 0; row < m; row++) {
            dfs(row, 0, heights, floodFromPacific);
            dfs(row, n - 1, heights, floodFromAtlantic);
        }
        
        for (int col = 0; col < n; col++) {
            dfs(0, col, heights, floodFromPacific);
            dfs(m - 1, col, heights, floodFromAtlantic);
        }
        
        vector<vector<int>> res;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (floodFromPacific[i][j] && floodFromAtlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
private:
    void dfs(int row, int col, vector<vector<int>>& heights, vector<vector<bool>>& visited) {
        visited[row][col] = true;
        
        for (int i = 0; i < 4; i++) {
            int rowTo = row + dir[i][0];
            int colTo = col + dir[i][1];
            
            if (rowTo < 0 || rowTo >= heights.size() || colTo < 0 || colTo >= heights[0].size() || visited[rowTo][colTo] || heights[rowTo][colTo] < heights[row][col]) { // '<' as we are flooding from the ocean, i.e., in the opposite direction as mentioned to the problem statement
                continue;
            }
            dfs(rowTo, colTo, heights, visited);
        }
    }
};