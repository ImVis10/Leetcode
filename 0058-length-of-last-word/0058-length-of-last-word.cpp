class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        bool spacesAfterLastWord = true;
        int res = 0;
        
        for (int i = len - 1; i >= 0; i--) {
            if (spacesAfterLastWord && s[i] == ' ') {
                continue;
            } else if (s[i] != ' ') {
                res++;
                spacesAfterLastWord = false;
            } else {
                break;
            }
        }
        return res;
    }
};