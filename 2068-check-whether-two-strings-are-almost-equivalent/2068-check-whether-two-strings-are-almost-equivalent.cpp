class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int> freq1(26), freq2(26);
        
        int len1 = word1.length(), len2 = word2.length();
        
        for (int i = 0; i < len1 ; i++) {
            freq1[word1[i] - 'a']++;
        }
        
        for (int i = 0; i < len2 ; i++) {
            freq2[word2[i] - 'a']++;
        }
        
        for (int i = 0; i < 26; i++) {
            if (abs(freq1[i] - freq2[i]) > 3) return false;
        }
        return true;
    }
};