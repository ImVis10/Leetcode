class Solution {
public:
    int numberOfMatches(int n) {
        int res = 0;
        while (n >= 2) {
            res += n / 2;
            n = n % 2 == 0 ? n / 2 : ((n - 1) / 2) + 1;
        }
        return res;
    }
};