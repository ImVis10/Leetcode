class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {        
        unordered_map<int, int> mp;
        
        for (int num : nums) mp[num]++;
        
        priority_queue<pair<int, int>> pq;
        
        for (auto& [k, v] : mp) pq.push({v, k});
        
        vector<int> res;
        
        while (k--) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};