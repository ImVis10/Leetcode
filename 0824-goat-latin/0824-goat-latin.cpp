class Solution {
public:
    string toGoatLatin(string sentence) {
        int wordIdx = 0;
        stringstream ss(sentence);
        string word, res;
        while (ss >> word) {
            wordIdx++;
            res += (isVowel(tolower(word[0])) ? word : word.substr(1) + word[0]) + "ma";
            res += string(wordIdx, 'a') + " ";
        }
        return res.substr(0, res.length() - 1);
    }
private:
    bool isVowel(char ch) {
        return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u';
    }
};