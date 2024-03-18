class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size(), res = 1;
        
        /**
         When balloons are sorted by their end positions, shooting an arrow at the end position of the first balloon ensures that any other balloon whose start position is before or at this end position will be covered by this shot. This maximizes the number of balloons that can be burst with a single arrow.
        **/
        sort(points.begin(), points.end(), [](auto const& a, auto const& b) {
            return a[1] < b[1];
        });
        
        int currStart, currEnd, prevEnd = points[0][1];

        for (auto& point : points) {
            currStart = point[0];
            currEnd = point[1];
            
            if (currStart > prevEnd) {
                res++;
                prevEnd = currEnd;
            }
        }
        return res;
    }
};