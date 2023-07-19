class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        unordered_map<char, int> freq;
        int freqOfMaxOccChar = 0, res = 0;
        for (int i = 0, j = 0; j < n; j++) {
            freq[s[j]]++;
            freqOfMaxOccChar = max(freqOfMaxOccChar, freq[s[j]]);
            int numCharsToChange = (j - i + 1) - freqOfMaxOccChar;
            if (numCharsToChange > k) freq[s[i++]]--;
            res = max(res, j - i + 1);
        }
        return res;
    }
};