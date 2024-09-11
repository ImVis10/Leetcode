class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorVal = start ^ goal;
        int oneBitCnt = 0;
        
        /** using brian kernighan's algo which only iterates as many times as the number of 1 bits in a number
        Brian Kernighan’s algorithm provides an efficient way to count the number of set bits (1s) in an integer by repeatedly eliminating the lowest set bit at each step. The algorithm leverages a clever trick: subtracting 1 from a number flips all the bits after the rightmost 1, including the rightmost 1 itself. When we perform a bitwise AND between the original number and the result of subtracting 1, this operation removes the lowest set bit. This is a nifty observation based on different examples.

If you start with:

n = 1101100 & n-1 = 1101011 => 1101000
n = 1101000 & n-1 = 1100111 => 1100000
n = 1100000 & n-1 = 1011111 => 1000000
n = 1000000 & n-1 = 0111111 => 0000000
So this iterates 4 times. Each iteration removes the least significant bit that is set to 1.**/
        
        while (xorVal) {
            xorVal &= (xorVal - 1);
            oneBitCnt++;
        }
        return oneBitCnt;
    }
};