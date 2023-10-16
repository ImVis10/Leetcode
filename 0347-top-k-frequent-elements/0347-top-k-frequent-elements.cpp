class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {   
        // TC is not better tha O(n log n)
//         unordered_map<int, int> mp;
        
//         for (int num : nums) mp[num]++;
        
//         priority_queue<pair<int, int>> pq;
        
//         for (auto& [k, v] : mp) pq.push({v, k});
        
//         vector<int> res;
        
//         while (k--) {
//             res.push_back(pq.top().second);
//             pq.pop();
//         }
//         return res;
        
        // O(n) TC
        // A variation of bucket sort
        int n = nums.size();
        unordered_map<int, int> mp;
        
        vector<vector<int>> freq(n + 1);
        
        for (int num : nums) mp[num]++;
        
        for (auto& [num, cnt] : mp) {
            freq[cnt].push_back(num);
        }
        
        vector<int> res;
        
        for (int i = freq.size() - 1; i > 0; i--) {
            if (k == 0) return res;
            if (freq[i].empty()) continue;
            for (int num : freq[i]) {
                if (k) {
                    res.push_back(num);
                    k--;
                }

            }
        }
        return res;
     }
};