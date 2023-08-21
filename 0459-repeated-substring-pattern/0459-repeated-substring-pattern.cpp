class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        string substr = "";
        for (int i = 0; i < len; i++) {
            substr += s[i];
            int lenSubStr = substr.length();
            if (len % lenSubStr != 0) continue;
            string repeatedSubStr = "";
            for (int j = 0; j < (len / lenSubStr); j++) {
                repeatedSubStr += substr;
                // if (s.substr(0, repeatedSubStr.length()) != repeatedSubStr) break;
            }
            if (s == repeatedSubStr && len != lenSubStr) return true;
        }
        
        return false;
    }
};