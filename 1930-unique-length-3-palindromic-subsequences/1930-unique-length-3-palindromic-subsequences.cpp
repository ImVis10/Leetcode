class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        unordered_map<char, pair<int, int>> mp;
        
        for (int i = 0; i < n; i++) {
            if (mp.find(s[i]) != mp.end()) mp[s[i]].second = i;
            else mp[s[i]] = {i, -1};
        }
        
        int res = 0;
            
        for (auto& [k, v] : mp) {
            int start = v.first, end = v.second;
            if (end == -1) continue;
            string between = s.substr(start + 1, end - start - 1);
            set<char> set = makeSet(between);
            res += set.size();
        }
        return res;
        
    }
private:
    set<char> makeSet(string& s) {
        set<char> set;
        for (char ch : s) set.insert(ch);
        return set;
    }
};