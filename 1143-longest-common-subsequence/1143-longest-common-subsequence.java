class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int l1 = text1.length();
        int l2 = text2.length();
        int[][] res = new int[l1+1][l2+1];
        for(int i = 0; i <=l1; i++) {
            for(int j = 0; j <=l2; j++) {
                if(i == 0 || j == 0) {
                    res[i][j] = 0;
                }
                else if(text1.charAt(i - 1) == text2.charAt(j - 1)) {
                    res[i][j] = res[i-1][j-1] + 1;
                } else {
                    res[i][j] = Math.max(res[i-1][j], res[i][j-1]);
                }
            }
        }
        return res[l1][l2];
    }
}