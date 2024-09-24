class Solution {
public:
    string customSortString(string order, string s) {
        string res;
        unordered_map<char, int> mp;
        // get the counts of each char in s
        for (char ch : s) mp[ch]++;
        // check for the chars in 's' that are present in 'order'
        for (char ch : order) {
            if (mp.find(ch) != mp.end()) {
                while (mp[ch]-- > 0) {
                    res += ch;
                } 
            }
        }
        // for chars in 's' that are not in 'order'
        for (auto& [ch, cnt] : mp) {
            while (cnt-- > 0) {
                res += ch;
            }
        }
        return res;
    }
};