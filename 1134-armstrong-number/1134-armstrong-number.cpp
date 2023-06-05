class Solution {
public:
    bool isArmstrong(int n) {
        int numDigits = ceil(log10(n));
        
        int n1 = n;
        int arm = 0;
        
        while (n != 0) {
            int rem = n % 10;
            arm += pow(rem, numDigits);
            n /= 10;
        }
        return arm == n1;
    }
};