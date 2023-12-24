class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        
        int startsWithZero = 0, startsWithOne = 0;
        
        for (int i = 0; i < n; i++) {
            int ch = s[i] - '0';
            if (ch == i % 2) startsWithZero += 1;
            else startsWithOne += 1;
        }
        return min(startsWithZero, startsWithOne);
    }
};