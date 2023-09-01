class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        
        for (auto& str : strs) {
            string s = str;
            sort(str.begin(), str.end());
            map[str].push_back(s);
        }
        
        vector<vector<string>> res;
        for (auto i = map.begin(); i != map.end(); i++) {
            res.push_back(i->second);
        }
        return res;
    }
};