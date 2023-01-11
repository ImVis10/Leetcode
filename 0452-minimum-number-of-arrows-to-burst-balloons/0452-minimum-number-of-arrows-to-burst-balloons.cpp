class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // Can make use of greedy approach
        // try to shoot an an arrow in such a manner that it bursts as many balloons as it can
        // to achieve that balloons must be sorted in the increasing order of their ending positions
        
        sort(points.begin(), points.end(), [](auto const &a, auto const &b) {
            return a[1] < b[1];
        });
        
        int numArrows = 1;
        int currStart, currEnd, prevEnd = points[0][1];
        
        for (auto point : points) {
            currStart = point[0];
            currEnd = point[1];
            
            if (currStart > prevEnd) { // if the current balloon starts after the end of the previous one, an extra arrow is needed.
                prevEnd = currEnd;
                numArrows++;
            }
        }
        return numArrows;
    }
};