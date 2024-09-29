class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0 or x == 1) return 1;
        if (x == 1) return 1;
        
        long long longN = n;
        
        if (n < 0) {
            x = 1 / x;
            longN = -longN; 
        }
        
        double res = 1;
        while (longN) {
            if (longN % 2 == 1) {
                res *= x;
                longN--;
            }
            x *= x;
            longN /= 2;
        }
        return res;
    }
};