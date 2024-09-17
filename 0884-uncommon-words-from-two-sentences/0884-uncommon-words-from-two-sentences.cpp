#include<algorithm>
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        
        getWordCount(s1, mp);
        getWordCount(s2, mp);
        
        vector<string> res;
        
        for (auto&[word, count] : mp) {
            if (count == 1) {
                res.push_back(word);
            }
        }
        
        return res;
        
    }
    
private:
    void getWordCount(string s, unordered_map<string, int>& mp) {
        stringstream ss(s);
        string word;
        while (ss >> word) {
            mp[word]++;
        }
    }
};