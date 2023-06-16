class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        int n = columnNumber;
        while (n > 0) {
            char ch = 'A' + --n % 26; // --n as 0-> A, 25->Z
            res = ch + res;
            n /= 26;
        }
        
        return res;
    }
};