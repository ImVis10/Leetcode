class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        map<int, string> mp;
        for (int i = 0; i < n; i++) {
            mp[heights[i]] = names[i];
        }
        
        vector<string> res(n);
        int idx = 0;
        
        for (auto& [k, v] : mp) {
            res[n - idx - 1] = v;
            idx++;
        }
        return res;
    }
};