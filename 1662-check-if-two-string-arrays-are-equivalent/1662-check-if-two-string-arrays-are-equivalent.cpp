class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0, j = 0;
        
        int w1 = 0, w2 = 0;
        
        while (i < word1.size() && j < word2.size()) {
            if (word1[i][w1] != word2[j][w2]) return false;
        
            if (++w1 == word1[i].size()) {
                i++;
                w1 = 0;
            }

            if (++w2 == word2[j].size()) {
                j++;
                w2 = 0;
            }
        }
        return i == word1.size() && j == word2.size();
    }
};