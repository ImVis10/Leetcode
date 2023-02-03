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
                } else if (w1[j] != w2[j]) { // if a mismatch found
                    if (map[w1[j]] > map[w2[j]]) { // if char in w1 is lexicographically after char in w2, words are not in correct lexicographical order
                        return false;
                    } else { // go to the next pair of words
                        break;
                    }
                }
            }
        }
        return true; // if all the pair of words are in lexicographical order
    }
};