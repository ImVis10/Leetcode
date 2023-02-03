class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> map; // mapping of alphabet and its position
        int pos = 0;
        
        for (char ch : order) {
            map[ch] = pos++; 
        }
        
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i], w2 = words[i + 1];
            
            for (int j = 0; j < w1.length(); j++) {
                if (j == w2.length()) { // if w2 is a prefix of w1, w2 is lexicographically before w1
                    return false;
                } else if (w1[j] != w2[j]) {
                    if (map[w1[j]] > map[w2[j]]) {
                        return false;
                    } else {
                        break;
                    }
                }
            }
        }
        return true;
    }
};