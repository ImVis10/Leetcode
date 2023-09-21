class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int rooms = 0;
        
        for (int i = 0; i < intervals.size(); i++) {
            if (pq.empty() or pq.top() > intervals[i][0]) { // allocate new room
                rooms++;
            } else {
                pq.pop();
            }
            pq.push(intervals[i][1]);
        }
        return rooms;
    }
};