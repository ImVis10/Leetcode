class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int num : nums) { // map of elements and their counts
            map[num] += 1;
        }
        
        priority_queue<pair<int, int>> pq; // priority queue (max_heap) based on their counts
        for (auto [a, b] : map) {
            pq.push({b, a});
        }
        
        vector<int> res;
        while (k) { // get the top, add it to result and pop it until k = 0
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return res;
    }
};