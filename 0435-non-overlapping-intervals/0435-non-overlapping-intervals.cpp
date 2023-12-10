class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>&b) {
           return a[1] < b[1]; 
        });
        
        int end = intervals[0][1];
        int res = 0;
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < end) res++;
            else end = intervals[i][1];
        }
        return res;
    }
};