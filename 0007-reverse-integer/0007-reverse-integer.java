class Solution {
    public int reverse(int x) {
        int res = 0;
        while(x != 0) {
            int rem = x % 10;
            int temp = res * 10 +  rem;
            if((temp - rem) / 10 !=  res) { // for numbers outside the range [-2^31, 2^31 - 1]
                return 0;
            }
            res = temp;
            x /= 10;
        }
        return res;
    }
}