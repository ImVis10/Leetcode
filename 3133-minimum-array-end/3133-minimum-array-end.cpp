class Solution {
public:
    long long minEnd(int n, int x) {
        long andRes = x;
        while (--n) {
            andRes = (andRes + 1) | x;
        }
        return andRes;
    }
};