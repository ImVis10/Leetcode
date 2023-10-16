class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.length(), n = t.length();
        if (m != n) return false;
        
        unordered_map<char, int> mp;
        
        for (int i = 0; i < m; i++) {
            mp[s[i]]++;
            mp[t[i]]--;
        }
        
        for (auto& [ch, cnt] : mp) {
            if (cnt != 0) return false;
        }
        return true;
    }
};