class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        // minimum cost to reach from top to bottom (of a traingle)
        // DP can be used as this is an optimization problem
        // from arr[row][col] can move to arr[row][col + 1] but not to arr[row][col - 1] or arr[row][col + 2]...
        // lets come up with recurrence relation
        // dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]) while coming from top to bottom
        // every cell has 2 cells below it
        List<Integer> belowRow = triangle.get(triangle.size() - 1);
        for (int row = triangle.size() - 2; row >= 0; row--) {
            List<Integer> currRow = new ArrayList<>();
            for (int col = 0; col <= row; col++) { // col in each row goes from 0 to row i.e. 3rd row (2nd row -- as we follow zero indexing) has 3 elements of indices 0,1,2
                int minBelow = Math.min(belowRow.get(col), belowRow.get(col + 1));
                currRow.add(minBelow + triangle.get(row).get(col));
            }
            belowRow = currRow;
        }
        return belowRow.get(0);
    }
}