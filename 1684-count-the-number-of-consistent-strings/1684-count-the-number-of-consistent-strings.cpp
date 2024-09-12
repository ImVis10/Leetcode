class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int n = words.size();
        int res = n;
        vector<int> chars(26);
        for (char& ch : allowed) chars[ch - 'a'] = 1;
        for (string& word : words) {
            for (char& ch : word) {
                if (chars[ch - 'a'] != 1) {
                    res--;
                    break;
                }
            }
        }
        return res;
    }
};