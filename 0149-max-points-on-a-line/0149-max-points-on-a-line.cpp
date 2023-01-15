class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        // Any 2 points can form a line
        // Another point can join that line if it has the same slope
        
        int res = 1;
        
        for (auto& p1 : points) {
            unordered_map<double, int> map;
            for (auto& p2 : points) {
                if (p1 == p2) continue;
                double slope = numeric_limits<double>::infinity();
                if (p1[0] - p2[0] != 0) {
                    slope = (double)(p2[1] - p1[1]) / (p2[0] - p1[0]);
                }
                map[slope] += 1;
                res = max(res, map[slope] + 1);
            }
        }
        return res;
    }
};