class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0 || x == 1) {
            return 1;
        } else if (n == 1) {
            return x;
        }
        
        long long longN = n;
        if (n < 0) {
            x = 1 / x;
            longN = -longN;
        }
        double res = myPow(x, longN / 2);
        res *= res;
        if (longN % 2 == 1) {
            res *= x;
        }
        return res;
    }
};