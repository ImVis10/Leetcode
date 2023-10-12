class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        
        unordered_map<char, int> map;
        int res = 0;
        
        for (int i = 0, j = 0; j < n; j++) {
            map[s[j]]++;
            while (map[s[j]] > 1) {
                --map[s[i++]];
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};