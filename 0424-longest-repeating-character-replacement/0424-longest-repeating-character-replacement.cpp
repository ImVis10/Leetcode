class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        
        unordered_map<char, int> map;
        int mostFreqChar = 0, res = 0;
        
        for (int i = 0, j = 0; j < n; j++) {
            map[s[j]]++;
            mostFreqChar = max(mostFreqChar, map[s[j]]);
            int numCharsToChange = (j - i + 1) - mostFreqChar;
            if (numCharsToChange > k) {
                --map[s[i++]];
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};