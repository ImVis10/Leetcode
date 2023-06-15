class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int numRows = matrix.size();
        int numCols = matrix[0].size();
        
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // right --> down --> left --> up
        
        int currDir = 0, changeInDir = 0;
        
        int currRow = 0, currCol = 0;
        
        vector<int> res;
        res.push_back(matrix[currRow][currCol]);
        
        int visited = 101;
        matrix[currRow][currCol] = visited;
        
        while (changeInDir < 2) {
            while (currRow + dir[currDir][0] >= 0 && currRow + dir[currDir][0] < numRows && currCol + dir[currDir][1] >= 0 && currCol + dir[currDir][1] < numCols && matrix[currRow + dir[currDir][0]][currCol + dir[currDir][1]] != visited) {
                changeInDir = 0;
                currRow += dir[currDir][0];
                currCol += dir[currDir][1];
                res.push_back(matrix[currRow][currCol]);
                matrix[currRow][currCol] = visited;
            }
            currDir = (currDir + 1) % dir.size();
            changeInDir++;
        }
        return res;
    }
};