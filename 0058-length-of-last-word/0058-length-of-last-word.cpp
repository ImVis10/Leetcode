class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        bool flag = false;
        int res = 0;
        
        for (int i = len - 1; i >= 0; i--) {
            if (flag && s[i] == ' ') {
                return res;
            } else if (s[i] == ' ') {
                continue;
            } else {
                res++;
                flag = true;
            }
        }
        return res;
    }
};