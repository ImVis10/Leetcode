class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        // to return the same matrix in a spiral order
        // is it possible to do this without using extra space?
        // first solving it normally
        // seems similar to flood fill problem. DFT can be used I guess
        int nRows = matrix.length;
        int nCols = matrix[0].length;
        
        int[][] dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // right -> down -> left -> up
        
        int currDir = 0, changeInDir = 0;
        
        int currRow = 0, currCol = 0, visited = 111;
        
        List<Integer> res = new ArrayList<>();
        res.add(matrix[currRow][currCol]);
        matrix[currRow][currCol] = visited;
        
        while (changeInDir < 2) { // if we change the direction in two consecutive iterations, it means that we are visiting the elements which are already visited and the objective is achieved.
            // int moveToRow = currRow + dir[currDir][0];
            // int moveToCol = currCol + dir[currDir][1];
            while (currRow + dir[currDir][0] >= 0 && currRow + dir[currDir][0] < nRows && currCol + dir[currDir][1] >= 0 && currCol + dir[currDir][1] < nCols && matrix[currRow + dir[currDir][0]][currCol + dir[currDir][1]] != visited) {
                changeInDir = 0; // reset to 0 if we're moving in the same direction.
                currRow += dir[currDir][0];
                currCol += dir[currDir][1];
                res.add(matrix[currRow][currCol]);
                matrix[currRow][currCol] = visited;
            }
            currDir = (currDir + 1) % dir.length; // changing the direction, in this order right -> down -> left -> up
            changeInDir++;
        }
        return res;
    }
}