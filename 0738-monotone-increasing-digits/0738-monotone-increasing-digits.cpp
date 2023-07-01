class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int i = 1, len = s.length();
        
        while (i < len && s[i - 1] <= s[i]) {
            i++;
        }
        
        if (i == len) {
            return n;
        }
        
        if (i < len) {
            while (i > 0 && s[i - 1] > s[i]) {
                s[--i]--;
            }
        }
        
        for (int j = i + 1; j < len; j++) {
            s[j] = '9';
        }
        return stoi(s);
    }
};