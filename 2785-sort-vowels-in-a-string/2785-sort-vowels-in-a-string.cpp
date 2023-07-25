class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;
        for (auto& ch : s) {
            if (isVowel(ch)) vowels.push_back(ch);
        }
        sort(vowels.begin(), vowels.end());
        reverse(vowels.begin(), vowels.end());
        
        string res = "";
        for (int  i = 0; i < s.length(); i++) {
            if (isVowel(s[i])) {
                res += vowels.back();
                vowels.pop_back();
            } else {
                res += s[i];
            }
        }
        return res;
    }
private:
    bool isVowel (char x) {
	    char y = toupper(x);
	    return (y =='A' || y =='E' || y =='I'|| y =='O'|| y =='U');
    }
};