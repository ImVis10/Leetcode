class Solution {
    public int[] findBall(int[][] grid) {
        int[] res = new int[grid[0].length]; // one for each ball
        for (int col = 0; col < grid[0].length; col++) { // for every ball
            int currCol = col;
            for (int row  = 0; row < grid.length; row++) {
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