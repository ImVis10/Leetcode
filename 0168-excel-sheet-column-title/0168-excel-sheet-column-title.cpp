class Solution {
public:
    string convertToTitle(int columnNumber) {
        int n = columnNumber;
        string res = "";
        while (n) {
            res += 'A' + (--n % 26);
            n /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};