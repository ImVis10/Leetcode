class Solution {
public:
    bool isPalindrome(string s) {
        string noSpecialCharString = "";
        
        for (char c : s) {
            if (c >= 'A' && c <= 'Z') {
                noSpecialCharString += tolower(c);                
            } else if (c >= 'a' && c <= 'z' || c >= '0' && c <= '9') {
                noSpecialCharString += c;
            }
        }
        return checkPalindrome(noSpecialCharString);
    }
private:
    bool checkPalindrome(string noSpecialCharString) {
        int n = noSpecialCharString.size();
        for (int i = 0; i < n / 2; i++) {
            if (noSpecialCharString[i] != noSpecialCharString[n - i - 1]) return false;
        }
        return true;
    }
};