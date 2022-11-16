class Solution {
    public int[] findBall(int[][] grid) {
        int[] res = new int[grid[0].length]; // one for each ball
        for (int col = 0; col < grid[0].length; col++) { // for every ball
            int currCol = col;
            for (int row  = 0; row < grid.length; row++) { // ball goes to next column only if the cell and its adjacent cell(in next column) have the same value. But the next column can be right or left sloped. So to calculate next column we can either do currCol - 1 or currCol + 1 i.e. currCol + grid[row][nextCol]. Ball can't go if the ball hits either of the walls as well i.e. 0, numColumns  - 1
                int nextCol = currCol + grid[row][currCol];
                if (nextCol < 0 || nextCol > grid[0].length - 1 || grid[row][currCol] != grid[row][nextCol]) {
                    res[col] = -1;
                    break;
                }
                currCol = nextCol;
                res[col] = nextCol;
            }
        }
        
        return res;
    }
}