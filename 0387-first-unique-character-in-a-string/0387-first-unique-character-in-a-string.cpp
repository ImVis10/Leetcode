class Solution {
public:
    int firstUniqChar(string s) {
        int cnt[26] = {0};
        /** any element in the array would be among the 3 values (-1, 0, x)
        -1 --> element present more than once
        0 --> element not present
        x --> element present only once at index x - 1**/
        for (int i = 0; i < s.length(); i++) {
            int ch = s[i] - 'a';
            if (cnt[ch] != 0) {
                cnt[ch] = -1;
            } else {
                cnt[ch] = i + 1;
            }
        }
        
        int res = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0) {
                res = min(cnt[i] - 1, res);
            }
        }
        return res != INT_MAX ? res : -1;
    }
};