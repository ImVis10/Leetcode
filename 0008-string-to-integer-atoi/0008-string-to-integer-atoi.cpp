class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;
        
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        int sign = 1;
        
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        
        return recurse(i, s, sign, 0);
    }
        
private:
    long recurse(int idx, string s, int sign, long res) {
        if (sign * res > INT_MAX) return INT_MAX;
        if (sign * res < INT_MIN) return INT_MIN;
        
        if (idx >= s.length() || s[idx] < '0' || s[idx] > '9') {
            return sign * res;
        }
        
        res = recurse(idx + 1, s, sign, res * 10 + s[idx] - '0');
        return res;
    }
};