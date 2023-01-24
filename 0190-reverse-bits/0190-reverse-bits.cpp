class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0, power = 31;
        while (n > 0) {
            res += (n & 1) << power;
            n = n >> 1; // as the bit has been processed, do a right shift;
            power--;
        }
        return res;
    }
};