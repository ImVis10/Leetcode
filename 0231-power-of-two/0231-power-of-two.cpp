class Solution {
public:
    bool isPowerOfTwo(int n) {
        // 2 complement of a number = convert +ve number to a -ve number
        // 2 complement of x = ~x + 1
        // all bits are inverted except the rightmost 1-bit
        // so x & (-x) keeps the rightmost 1-bit intact and clears rest of the bits to 0
        
        // since for a power of 2 only 1 bit is set and rest all are 0s, our job would be just to check
        // if x & (-x) == x
        if (n == 0)
            return false;
        long x = n;
        return (x & (-x)) == x;
    }
};