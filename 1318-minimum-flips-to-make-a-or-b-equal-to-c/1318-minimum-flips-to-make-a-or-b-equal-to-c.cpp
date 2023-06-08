class Solution {
public:
    int minFlips(int a, int b, int c) {
        // to flip kth bit ==> num ^ (1 << k)
        int numFlips = 0;
        for (int i = 0; i < 32; i++) {
            int getBitA = bool(a & (1 << i));
            int getBitB = bool(b & (1 << i));
            int getBitC = bool(c & (1 << i));
            if (getBitC == 0) {
                if (getBitC != getBitA) { // both a and b bits should be 0 for c bit to be 0 as we're doing an OR
                    numFlips++;
                }
                if (getBitC != getBitB) {
                    numFlips++;
                }
            } else if (getBitC != getBitA && getBitC != getBitB) { // if c bit == 1, then even if both a and b bits are 0, flipping one of them suffices
                    numFlips++;
            }
        }
        return numFlips;
    }
};