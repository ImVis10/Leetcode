class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for (int num1 : nums1) {
            pq.push({num1 + nums2[0], 0});
        }
        
        while (k-- && !pq.empty()) {
            int sum = pq.top().first;
            int idx = pq.top().second;
            
            res.push_back({sum - nums2[idx], nums2[idx]});
            pq.pop();
            
            if (idx + 1 < nums2.size()) {
                pq.push({sum - nums2[idx] + nums2[idx + 1], idx + 1});
            }
        }
        return res;
    }
};