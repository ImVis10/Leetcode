class Solution {
public:
    string compressedString(string word) {
        /**
        aaaaaaaaaaaaaabb
        123456789abcde    
        9a5a1b1c1d1e
        **/
        string comp;
        int n = word.length();
        for (int i = 0, j = 0; j < n; j++) {
            if ((word[j] == word[j + 1] and j - i + 1 == 9) or word[j] != word[j + 1]) {
                comp += to_string(j - i + 1);
                comp += word[j];
                i = j + 1;
            }
        }
        return comp;
    }
};