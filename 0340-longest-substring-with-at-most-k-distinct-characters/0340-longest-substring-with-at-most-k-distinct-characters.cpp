class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.length();
        int res = 0;
        unordered_map<char, int> freq;
        for (int i = 0, j = 0; j < n; j++) {
            freq[s[j]]++;
            while (freq.size() > k) {
                if (--freq[s[i]] == 0) freq.erase(s[i]);
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};