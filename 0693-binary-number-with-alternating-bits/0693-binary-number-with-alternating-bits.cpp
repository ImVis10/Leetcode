class Solution {
public:
    bool hasAlternatingBits(int n) {
        int numBits = countBits(n);
        int prevBit = n & (1 << 0);
        for (int i = 1; i < numBits; i++) {
            int currBit = n & (1 << i);
            currBit = 1 ? currBit != 0 : 0;
            if (currBit == prevBit) {
                return false;
            }
            prevBit = currBit;
        }
        return true;
    }

private:
    int countBits(int n) {
        int count = 0;
        while (n) {
            count++;
            n >>= 1;
        }
        return count;
    }
};