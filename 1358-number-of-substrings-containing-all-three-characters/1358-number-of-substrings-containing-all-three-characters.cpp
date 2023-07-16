class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> freq;
        int n = s.length(), count = 0;
        for (int i = 0, j = 0; j < n; j++) {
            freq[s[j]]++;
            while (freq.size() == 3) {
                if (--freq[s[i]] == 0) freq.erase(s[i]);
                i++;
            }
            count += i;
        }
        return count;
    }
};