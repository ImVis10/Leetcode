class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        
//         for (int i = 0; i < n; i++) {
//             int start = intervals[i][0];
//             int end = intervals[i][1];
            
//             if (!res.empty() && end <= res.back()[1]) {
//                 continue;
//             }
            
//             for (int j = i + 1; j < n; j++) {
//                 if (intervals[j][0] <= end) {
//                     end = max(end, intervals[j][1]);
//                 } else {
//                     break;
//                 }
//             }
//             res.push_back({start, end});
//         }
        
        // OPTIMAL APPROACH
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