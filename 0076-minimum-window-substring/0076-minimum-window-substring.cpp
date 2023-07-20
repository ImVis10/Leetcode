class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        if (m < n) return "";
        
        unordered_map<char, int> map;
        
        for (auto& ch : t) {
            map[ch]++;
        }
        
        int foundCharsFromT = 0, validMinWindowLen = INT_MAX, moveStart = 0;
        for (int i = 0, j = 0; j < m; j++) {
            if (--map[s[j]] >= 0) foundCharsFromT++;
            while (foundCharsFromT == n) {
                if (j - i + 1 < validMinWindowLen) {
                    validMinWindowLen = j - i + 1;
                    moveStart = i;
                }
                map[s[i]]++;
                if (map[s[i++]] > 0) foundCharsFromT--; // > 0 because only then we're sure that we found char from T in S.
            }
        }
        return validMinWindowLen != INT_MAX ? s.substr(moveStart, validMinWindowLen) : "";
        // since it's a minimum window, the window must shrink
    }
};