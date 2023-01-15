class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        // Any 2 points can form a line
        // Another point can join that line if it has the same slope
        // for each point determine if it is on the longest line
        
        int res = 1;
        
        for (auto& p1 : points) {
            unordered_map<double, int> map; // key = slope, value = number of points with slope 'slope'
            for (auto& p2 : points) {
                if (p1 == p2) continue; // points are the same, so continue
                double slope = numeric_limits<double>::infinity(); // default slope is infinity
                if (p1[0] != p2[0]) { // if both the y coordinates are not equal, it means that slope is not infinity, so calculate the slope
                    slope = (double)(p2[1] - p1[1]) / (p2[0] - p1[0]);
                }
                map[slope] += 1; // increment the number of points with the same slope
                res = max(res, map[slope] + 1); // adding 1 to map[slope] to include the point p1
            }
        }
        return res;
    }
};