class Solution {
public:
    bool halvesAreAlike(string s) {
        string a = s.substr(0, s.length() / 2);
        string b = s.substr(s.length() / 2);
        
        return countVowel(a) == countVowel(b);
    }
    
private:
    int countVowel(string str) {
        int count = 0;
        for (char ch : str) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                count++;
            }
        }
        return count;
    }
};