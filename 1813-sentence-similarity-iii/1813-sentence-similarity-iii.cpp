class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        // say s1 is the smaller sentence
        // for the sentences to be similar
        // s1 must either be
        // 1. prefix of s2
        // 2. suffix of s2
        // 3. prefix and suffix of s2
        vector<string> words1 = split(sentence1, ' ');
        vector<string> words2 = split(sentence2, ' ');
        
        if (words1.size() > words2.size()) { // just for the sake that words1 will always be the smaller one, for easier comparison
            swap(words1, words2);
        }
        
        int m = words1.size(), n = words2.size();
        
        int l1 = 0, l2 = 0, r1 = m - 1, r2 = n - 1;
        
        while (l1 < m and l2 < n and words1[l1] == words2[l2]) {
            l1++;
            l2++;
        }
        
        while (r1 >= 0 and r2 >= 0 and words1[r1] == words2[r2]) {
            r1--;
            r2--;
        }
        return l1 > r1;
    }
private:
    vector<string> split(string str, char delim) {
        vector<string> words;
        stringstream ss(str);
        string word;
        while (getline(ss, word, delim)) {
            words.push_back(word);
        }
        return words;
    }
};