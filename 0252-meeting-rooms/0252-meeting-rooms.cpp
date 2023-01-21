class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto const &a, auto const &b){
           return a[0] < b[0]; 
        });
        
        int currStart, currEnd, prevEnd = -1;
        
        for (auto interval : intervals) {
            currStart = interval[0];
            currEnd = interval[1];
            
            if (currStart < prevEnd) {
                return false;
            }
            prevEnd = currEnd;
        }
        return true;
    }
};