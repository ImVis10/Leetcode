class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length() - 1, j = num2.length() - 1;
        int carry = 0;
        string res;
        while (i >= 0 or j >= 0 or carry != 0) {
            if (i >= 0) carry += num1[i--] - '0';
            if (j >= 0) carry += num2[j--] - '0';
            res += to_string(carry % 10);
            carry /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};