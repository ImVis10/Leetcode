class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        
        stringstream stream(s);
        string word;
        
        while (stream >> word) {
            words.push_back(word);
        }
        
        if (pattern.length() != words.size()) {
            return false;
        }
        
        map<char, string> charToWord;
        map<string, char> wordToChar;
        
        for (int  i = 0; i < pattern.length(); i++) {
            if (charToWord.count(pattern[i]) != 0 && charToWord[pattern[i]] != words[i]) {
                return false;
            }
            if (wordToChar.count(words[i]) != 0 && wordToChar[words[i]] != pattern[i]) {
                return false;
            }
            
            charToWord[pattern[i]] = words[i];
            wordToChar[words[i]] = pattern[i];
        }
        return true;
        
    }
};