class Solution {
public:
    string customSortString(string order, string s) {
        string res = "";
        unordered_map<char, int> mp;
        for (char ch : s) mp[ch]++;
        for (char ch : order) {
            if (mp.count(ch) > 0) {
                while (mp[ch] > 0) {
                    res += ch;
                    mp[ch] -= 1;
                }
            }
        }
        for (auto [ch, cnt] : mp) {
            while (cnt > 0) {
                res += ch;
                cnt -= 1;
            }
        }
        return res;
    }
};