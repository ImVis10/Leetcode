class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int res = 0;
        unordered_map<char, int> freq;
        
        for (int i = 0, j = 0; j < n; j++) {
            freq[s[j]]++;
            while (freq[s[j]] > 1) {
                --freq[s[i]];
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};