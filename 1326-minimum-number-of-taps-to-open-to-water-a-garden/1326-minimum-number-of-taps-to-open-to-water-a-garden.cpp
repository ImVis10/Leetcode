class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {        
        vector<int> area(ranges.size(), 0);
        
        for (int i = 0; i < ranges.size(); i++) {
            int left = max(0, i - ranges[i]);
            area[left] = max(area[left], i + ranges[i]);
        }
        
        int end = 0, canReachEnd = 0, res = 0;
        
        for (int i = 0; i < ranges.size(); i++) {
            if (i > end) {
                if (canReachEnd <= end) {
                    return -1;
                }
                end = canReachEnd;
                res++;
            }
            canReachEnd = max(canReachEnd, area[i]);
        }
        
        return res + (end < n);
    }
};