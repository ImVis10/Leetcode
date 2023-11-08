class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int minTime = max(abs(fx - sx), abs(fy - sy));
        
        return minTime != 0 ? minTime <= t : t != 1;
    }
};