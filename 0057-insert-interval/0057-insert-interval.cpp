class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;
        
        intervals.push_back(newInterval);
        
        sort(intervals.begin(), intervals.end());
        
        // merge overlapping intervals
        for (int i = 0; i < n + 1; i++) { // < n + 1 as we added the newIntervals into our intervals, so its size increases
            if (res.empty() || intervals[i][0] > res.back()[1]) {
                res.push_back(intervals[i]);
            } else {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }
        return res;
    }
};