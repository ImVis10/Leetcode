class Solution {
public:
    int countDigits(int num) {
        // int res = 0;
        // int temp = num;
        // while(temp > 0) {
        //     int digit = temp % 10;
        //     temp /= 10;
        //     res += (num % digit == 0);
        // }
        // return res;
        
        // TOOK THIS SOLUTION FROM VORTUBAC AS ITS NEATER ACCORDING TO ME
        auto str = to_string(num);
        return accumulate(begin(str), end(str), 0, [&](int res, char ch) {
            return res + (num % (ch - '0') == 0);
        });
    }
};