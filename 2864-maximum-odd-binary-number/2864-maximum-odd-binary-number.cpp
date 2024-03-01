class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        int zeroes = count(s.begin(), s.end(), '0'), ones = n - zeroes;
        return string(ones - 1, '1') + string(zeroes, '0') + string(1, '1');
    }
};