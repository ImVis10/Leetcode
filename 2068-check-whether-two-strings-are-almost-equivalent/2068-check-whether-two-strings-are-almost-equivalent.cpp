class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int> freq(26);
        
        int len1 = word1.length(), len2 = word2.length();
        
        for (int i = 0; i < len1 ; i++) {
            freq[word1[i] - 'a']++;
            freq[word2[i] - 'a']--;
        }

        
        for (int i = 0; i < 26; i++) {
            if (abs(freq[i]) > 3) return false;
        }
        return true;
    }
};