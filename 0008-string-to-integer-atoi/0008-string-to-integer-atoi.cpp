class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.length();
        int sign = 1;
        
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        return atoi(s, sign , i, 0);
    }
    
private:
    long atoi(string s, int sign, int idx, long res) {
        if (sign * res >= INT_MAX) return INT_MAX;
        if (sign * res <= INT_MIN) return INT_MIN;
        
        if (idx >= s.length() || s[idx] < '0' || s[idx] > '9') {
            return sign * res;
        }
        
        res = atoi(s, sign, idx + 1, (res * 10 + (s[idx] - '0')));
        return res;
    }
};