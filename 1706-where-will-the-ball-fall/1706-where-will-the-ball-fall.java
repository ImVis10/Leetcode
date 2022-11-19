class Solution {
    public int[] findBall(int[][] grid) {
        int numBalls = grid[0].length;
        int[] res = new int[numBalls];
        for (int col = 0; col < grid[0].length; col++) {
            int currCol = col;
            for (int row = 0; row < grid.length; row++) {
                int nextCol = currCol + grid[row][currCol];
                if (nextCol < 0 || nextCol >= numBalls || grid[row][currCol] != grid[row][nextCol]) { // can go to to the next row if and only the cell in the next column has the same values as itself i.e if 1st cell is left sloped, the next cell should be left sloped itself.
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