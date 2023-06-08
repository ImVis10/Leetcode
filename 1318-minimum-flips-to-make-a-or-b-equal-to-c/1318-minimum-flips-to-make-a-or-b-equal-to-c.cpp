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
                if (getBitC != getBitA) {
                    numFlips++;
                }
                if (getBitC != getBitB) {
                    numFlips++;
                }
            } else if (getBitC != getBitA && getBitC != getBitB) {
                    numFlips++;
            }
        }
        return numFlips;
    }
};