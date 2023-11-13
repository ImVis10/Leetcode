class Solution {
public:
    string reverseVowels(string s) {
        int n = s.length();
        
        int i = 0, j = n - 1;
        
        while (i < j) {
            if (string("aeiouAEIOU").find(s[i]) != string::npos && string("aeiouAEIOU").find(s[j]) != string::npos) {
                swap(s[i++], s[j--]);
            } 
            if (string("aeiouAEIOU").find(s[i]) == string::npos) {
                i++;
            } 
            if (string("aeiouAEIOU").find(s[j]) == string::npos) {
                j--;
            }
        }
        return s;
    }
};