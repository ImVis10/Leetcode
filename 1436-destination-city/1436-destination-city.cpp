class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        string dest = "";
        
        set<string> set;
        
        for (auto& path : paths) {
            set.insert(path[0]);
        }
        
        for (auto& path : paths) {
            if (set.find(path[1]) == set.end()) return dest = path[1];
        }
        return dest;
    }
};