class Solution {
public:
    int minimumOneBitOperations(int n) {
        // got from the solution section
        // will solve it later
        int res;
        for (res = 0; n > 0; n &= n - 1)
            res = -(res + (n ^ (n - 1)));
        return abs(res);
    }
};