class Solution {
    public int minScoreTriangulation(int[] values) {
        // Since this is a minimization problem, DP can be used.
        // length of the input array is equal to number of sides/vertices in the polygon 
        // a polygon is triangulated into n - 2 triangles
        int n = values.length;
        // int[][] dp = new int[n][n];
        // return pickThirdVertexAndSolveForSubProblems(values, 0, n - 1, dp);
        return useTabulation(values);
        
    }
    
    // shit.. forgot to cache the results. Got time limit exceeded.
    private int pickThirdVertexAndSolveForSubProblems(int[] values, int i, int j, int[][] dp) {
        if (i + 1 == j) return 0; // base case
        if (dp[i][j] != 0) return dp[i][j]; // return from cache if its already computed
        int res = Integer.MAX_VALUE;
        for(int k = i + 1; k < j; k++) {
            res = Math.min((values[i]*values[k]*values[j] + pickThirdVertexAndSolveForSubProblems(values, i , k, dp) + pickThirdVertexAndSolveForSubProblems(values, k , j, dp)), res);
        }
        dp[i][j] = res;
        return res;
    }
    
    private int useTabulation(int [] values) {
        int n = values.length;
        int[][] dp = new int[n][n];
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 2; j < n; j++) {
                int res = Integer.MAX_VALUE;
                for (int k = i + 1; k < j; k++) {
                    res = Math.min((values[i]*values[k]*values[j] + dp[i][k] + dp[k][j]), res);
                }
                dp[i][j] = res;
            }
        }
        return dp[0][n - 1];
    }
}