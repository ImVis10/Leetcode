class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        
        int n = intervals.size();
        
        sort(intervals.begin(), intervals.end());
        
        for (int i = 0; i < n; i++) {
            if (res.empty() || intervals[i][0] > res.back()[1]) {
                res.push_back(intervals[i]);
            } else {
                res.back()[1] = max(intervals[i][1], res.back()[1]);
            }
        }
        return res;
    }
};