class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        // sort the points in the increasing order of xend
        
        sort(points.begin(), points.end(), [](auto const &a, auto const &b) {
            return a[1] < b[1];
        });
        
        int numArrows = 1;
        int prevEnd = points[0][1];
        
        for(int i = 0; i < points.size(); i++) {
            int xStart = points[i][0];
            int xEnd = points[i][1];
            
            if (xStart > prevEnd) {
                numArrows++;
                prevEnd = xEnd;
            }
        }
        return numArrows;
    }
};