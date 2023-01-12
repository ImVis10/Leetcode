class Solution {
public:
    int countDigits(int num) {
        int res = 0;
        int temp = num;
        while(temp > 0) {
            int digit = temp % 10;
            temp /= 10;
            res += (num % digit == 0);
        }
        return res;
    }
};