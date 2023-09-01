class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int num : nums) {
            map[num]++;
        }
        
        priority_queue<pair<int, int>> pq;
        for (auto [k, v] : map) {
            pq.push({v, k});
        }
        
        vector<int> res;
        while (k--) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};