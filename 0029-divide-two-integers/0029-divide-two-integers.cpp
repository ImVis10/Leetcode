class Solution {
public:
    int divide(int dividend, int divisor) {  
        // any number left shifted (<<) 2 is multipled by 2
        // eg: 5 << 1 --> 5 is leftshifted one time, so multiplied by 2 once --> 5 * 2 = 10
        // eg: 5 << 2 --> 5 is leftshifted two times, so multiplied by 2 twice --> 5 * 2 * 2 = 20
        
        if (dividend == divisor) return 1;
        
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        unsigned int quotient = 0;
        
        unsigned int dividend1 = abs(dividend);
        unsigned int divisor1 = abs(divisor);
        
        while(dividend1 >= divisor1) {
            int twoPowerOfQuotient = 0;
            while ((divisor1 << (twoPowerOfQuotient + 1)) < dividend1) {
                twoPowerOfQuotient++;
            }
            quotient += (1 << twoPowerOfQuotient);
            dividend1 -= (divisor1 << twoPowerOfQuotient);
        }
        
        if (quotient > INT_MAX && sign == 1) {
            return INT_MAX ;
        }
        return quotient * sign;
    }
};