class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // same as meeting rooms ii
        sort(intervals.begin(), intervals.end());
        int groups = 0;
        
        priority_queue<int, vector<int>, greater<int>> pq; // min heap to store end times
        
        for (int i = 0; i < intervals.size(); i++) {
            if (pq.empty() or pq.top() >= intervals[i][0]) groups++;
            else pq.pop();
            pq.push(intervals[i][1]);
        }
        return groups;
    }
};