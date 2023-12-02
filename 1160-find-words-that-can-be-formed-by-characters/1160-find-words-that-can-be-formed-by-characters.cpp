class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int res = 0;
        
        unordered_map<char, int> mp1;
        
        for (char ch : chars) mp1[ch]++;
        
        for (string word : words) {
            unordered_map<char, int> mp2;
            bool wordForm = true;
            
            for (char ch : word) {
                mp2[ch]++;
                if (mp2[ch] > mp1[ch]) {
                    wordForm = false;
                    break;
                }
            }
            
            if (wordForm) res += word.size();
            
        }
        return res;
    }
};