class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int res = 0;
        
        unordered_map<char, int> mp1;
        
        for (char ch : chars) mp1[ch]++;
        
        for (string word : words) {
            unordered_map<char, int> mp2;
            for (char ch : word) {
                mp2[ch]++;
            }
            
            int cnt = 0;
            
            for (auto& [k, v] : mp2) {
                if (mp1.find(k) == mp1.end()) break;
                else if (mp1[k] >= mp2[k]) cnt++;
            }
            
            if (cnt == mp2.size()) res += word.size();
        }
        return res;
    }
};