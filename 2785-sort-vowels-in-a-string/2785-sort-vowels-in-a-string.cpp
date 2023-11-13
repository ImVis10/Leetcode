class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;
        
        for (char ch : s) {
            if (string("aeiouAEIOU").find(ch) != string::npos) {
                vowels.push_back(ch);
            }
        }
        
        sort(vowels.begin(), vowels.end());
        reverse(vowels.begin(), vowels.end());
        
        string res;
        
        for (char ch : s) {
            if (string("aeiouAEIOU").find(ch) != string::npos) {
                res += vowels.back();
                vowels.pop_back();
            } else {
                res += ch;
            }
        }
        return res;
    }
};