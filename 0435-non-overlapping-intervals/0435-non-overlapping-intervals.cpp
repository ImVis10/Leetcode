class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
//         if(intervals.size() <= 1) return 0;

//         sort(intervals.begin(), intervals.end());

//         int n= intervals.size();
//         vector<int> dp(n,1);

//         for(int i = 1; i < n; i++){
//             for(int j = i - 1; j >= 0; j--){
//                 if(intervals[j][1] <= intervals[i][0]){ // non-overlapping
//                     dp[i] = max(dp[i], dp[j] + 1);
//                 }
//             }
//         }
//         return n - dp[n-1];
        
        // DP must be an overkill for this problem I guess;
        
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        
        int res = 0;
        
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= intervals[i - 1][1]) continue; // if no overlap, go to next one (if there is an interval present)
            // if there is a overlap
            intervals[i][0] = intervals[i - 1][0];
            intervals[i][1] = min(intervals[i][1], intervals[i - 1][1]);
            res++;
        }
        return res;
        // BUT THE CATCH HERE IS I'M MODIFYING THE INPUT, WHICH IS NOT EXACTLY ADVISABLE IN THE INTERVIEWS AND GENERALLY NOT CONSIDERED A GOOD PRACTICE
    }
};