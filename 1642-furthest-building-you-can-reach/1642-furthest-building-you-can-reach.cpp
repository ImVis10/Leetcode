class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricksAvailable, int ladders) {
        int n = heights.size();
        priority_queue<int> pq;
        int i = 0, bricksNeeded = 0;
        for (i = 0; i < n - 1; i++) {
            bricksNeeded = heights[i + 1] - heights[i];
            if (bricksNeeded <= 0) continue;
            pq.push(bricksNeeded);
            bricksAvailable -= bricksNeeded;
            if (bricksAvailable < 0) {
                bricksAvailable += pq.top();
                pq.pop();
                ladders -= 1;
            }
            if (ladders < 0) return i;
        }
        return i;
    }
};