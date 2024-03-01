class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int zeroes = 0, ones = 0;
        string res = "";
        for (char bit : s) {
            if (bit == '0') zeroes++;
            else ones++;
        }
        
        while (ones - 1 >= 1) {
            res += '1';
            ones--;
        }
        
        while (zeroes > 0) {
            res += '0';
            zeroes--;
        }
        
        res += '1';
        
        return res;
    }
};