class Solution {
    public int numIslands(char[][] grid) {
        // m x n array
        // assume the complete grid is surrounded by water on all the 4 sides.
        int row = grid.length, col = grid[0].length;
        int res = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    floodFill(grid, i , j); 
                    res++; // increment the count when all the adjacent lands to a land are visited i.e. when the recursive func is returned.
                }
            }
        }
        return res;
    }

    // using the same algo used for flood fill problem.
    private void floodFill(char[][] grid, int r, int c) {
        grid[r][c] = 'v'; // marking the cell as visited.
        int[][] dir = new int[][]{{1,0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < 4; i++) {
            int newRow = r + dir[i][0];
            int newCol = c + dir[i][1];
            // Got ArrayOutOfBounds exception. So adding this condition to see if the row and col didn't go out of image array's size.
            if (newRow >= 0 && newRow < grid.length && newCol >= 0 && newCol < grid[0].length && grid[newRow][newCol] == '1') {
                floodFill(grid, newRow, newCol); // try the same for neighbouring cell as well.
            }
        }
    }
}