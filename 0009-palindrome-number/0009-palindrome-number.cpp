class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        
        int rev = 0;
        int x1 = x;
        
        while (x != 0) {
            if (rev > INT_MAX / 10 || rev < INT_MIN / 10) {
                return false;
            }
            int rem = x % 10;
            int temp = rev * 10 + rem;
            rev = temp;
            x /= 10;
        }
        
        return x1 == rev;
    }
};