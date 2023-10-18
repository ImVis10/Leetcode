class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        
        for (auto& point : points) {
            pq.push({-(pow(point[0], 2) + pow(point[1], 2)), point});
        }
        
        vector<vector<int>> res;
        
        while (k--) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};