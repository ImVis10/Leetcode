class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, vector<int>> mp;
        int res = -1;
        
        for (int i = 0; i < s.length(); i++) {
            mp[s[i]].push_back(i);
        }
        
        for (auto &[ch, pos] : mp) {
            if (pos.size() > 1) {
                res = max(res, pos[pos.size() - 1] - pos[0] - 1);
            }
        }
        return res;
    }
};