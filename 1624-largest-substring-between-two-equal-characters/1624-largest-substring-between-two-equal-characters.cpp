class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> mp;
        int res = -1;
        
        for (int i = 0; i < s.length(); i++) {
            if (mp.find(s[i]) != mp.end()) res = max(res, i - mp[s[i]] - 1);
            else mp[s[i]] = i;
        }
        return res;
    }
};