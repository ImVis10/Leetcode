class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> mp;
        vector<vector<int>> res(2);
        
        for (auto& match : matches) {
            mp[match[0]];
            mp[match[1]]++;
        }
        
        for (auto& [player, loss] : mp) {
            if (loss <= 1) res[loss].push_back(player);
        }
        return res;
    }
};