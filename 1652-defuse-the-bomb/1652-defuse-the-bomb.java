class Solution {
    public int[] decrypt(int[] code, int k) {
        int n = code.length;
        int[] res = new int[n];
        if (k == 0) {
            return res;
        }
        
        if (k > 0) {
            for (int i = 0; i < code.length; i++) {
                int temp = k;
                while (temp > 0) {
                    res[i] += code[(i + temp) % n];
                    temp--;
                }
            }
            return res;
        }
        
        for (int i = 0; i < code.length; i++) {
            for (int j = i - 1; j > i + k - 1; j--) {
                res[i] += code[(j + n) % n];
            }
        }
        return res;
        
    }
}