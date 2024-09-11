class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorVal = start ^ goal;
        int oneBitCnt = 0;
        while (xorVal > 0) {
            if (xorVal & 1) oneBitCnt++;
            xorVal >>= 1;
        }
        return oneBitCnt;
    }
};