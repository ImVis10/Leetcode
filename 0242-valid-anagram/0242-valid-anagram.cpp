class Solution {
public:
    bool isAnagram(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();
        
        if (len1 != len2) {
            return false;
        }
        
        unordered_map<char,int> map;
        for (int i = 0; i < len1; i++) {
            map[s[i]]++;
            map[t[i]]--;
        }
        
        for (auto x : map) {
            if(x.second) {
                return false;
            }
        }
        return true;
    }
};