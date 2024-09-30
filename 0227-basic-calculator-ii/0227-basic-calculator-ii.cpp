class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        int currNum = 0, prevExpRes = 0, res = 0;
        char prevOp = '+';
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (isdigit(ch)) {
                currNum = (currNum * 10) + (ch - '0');
            }
            if (!isdigit(ch) and !iswspace(ch) or i == n - 1) {
                if (prevOp == '+' or prevOp == '-') {
                    res += prevExpRes;
                    prevExpRes = (prevOp == '+') ? currNum : -currNum;
                } else if (prevOp == '*') {
                    prevExpRes *= currNum;
                } else if (prevOp == '/') {
                    prevExpRes /= currNum;
                }
                prevOp = ch;
                currNum = 0;
            }
        }
        res += prevExpRes;
        return res;
    }
};