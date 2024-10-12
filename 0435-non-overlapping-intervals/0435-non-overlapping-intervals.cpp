class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // why sort by end time?
        /**If we have interval a and b, we found out that a overlaps with b. That means we can only keep one, the question is which one should we keep?
         Obviously we want to keep the one with smaller end, this way we have higher chance of putting other intervals after it.
         So we decided to sort by end time.**/
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