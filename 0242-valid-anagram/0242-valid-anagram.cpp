class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // return s == t;
        
        // ANSWER TO FOLLOW-UP QUESTION
        map<char, int> map;
        for (int i = 0; i < s.length(); i++) {
            map[s[i]]++;
            map[t[i]]--;
        }
        
        for (auto entry : map) {
            if (entry.second) {
                return false;
            }
        }
        return true;
    }
};