class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int res = 0;
        
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
           return a[1] < b[1]; 
        });
        
        int maxEnd = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            
            if (start >= maxEnd) maxEnd = end;
            else res++;
        }
        
        return res;
    }
};