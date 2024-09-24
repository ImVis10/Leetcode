class Solution {
public:
    string toGoatLatin(string sentence) {
        int wordIdx = 0;
        stringstream ss(sentence);
        string word, res;
        while (ss >> word) {
            wordIdx++;
            if (isVowel(tolower(word[0]))) {
                res += word + "ma";
            } else {
                res += word.substr(1, word.length() - 1) + word[0] + "ma";
            }
            for (int i = 0; i < wordIdx; i++) res += 'a';
            res += " ";
        }
        return res.substr(0, res.length() - 1);
    }
private:
    bool isVowel(char ch) {
        return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u';
    }
};