class Solution {
public:
    char findKthBit(int n, int k) {
        if (k == 1) return '0';
        int len = (1 << n) - 1, inSecondHalf = 0;
        while (k > 1) {
            if (k == len / 2 + 1) return inSecondHalf == 0 ? '1' : '0';
            if (k > len / 2) {
                k = len + 1 - k;
                inSecondHalf = !inSecondHalf;
            }
            len /= 2;
        }
        return inSecondHalf == 0 ? '0' : '1';
    }
};