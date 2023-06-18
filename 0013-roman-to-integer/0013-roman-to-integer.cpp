class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (i != n - 1 && (getValue(s[i]) < getValue(s[i + 1]))) {
                res -= getValue(s[i]);
            } else {
                res += getValue(s[i]);
            }
        }
        return res;
    }

private:
    int getValue(char ch) {
        switch(ch) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
};