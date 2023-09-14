class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gs) {
        int n = gs.size();
        
        unordered_map<int, vector<int>> map;
        
        for (int i = 0; i < n; i++) {
            map[gs[i]].push_back(i);
        }
        
        
        vector<vector<int>> res;
        for (auto& [k, v] : map) {
            for (int i = 0; i < v.size(); i += k) {
                vector<int> subRes(v.begin() + i, v.begin() + i + k);
                res.push_back(subRes);
            }
        }
        return res;
    }
};