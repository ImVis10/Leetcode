class Solution {
    
    public int rotatedDigits(int n) {
        
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if(isGoodNumber(i)) {
                res++;
            }
        }
        return res;
    }
    
    private boolean isGoodNumber(int n) {
        boolean isGoodNumber = false;
        while (n > 0) {
            int digit = n % 10;
            if(digit == 2 || digit == 5 || digit == 6 || digit == 9) {
                isGoodNumber = true;
            } else if (digit == 3 || digit == 4 || digit == 7) {
                return false;
            }
            n /= 10;
        }
        return isGoodNumber;
    }
}