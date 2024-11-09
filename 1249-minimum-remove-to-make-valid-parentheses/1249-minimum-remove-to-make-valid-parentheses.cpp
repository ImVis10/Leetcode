class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        int open = 0, close = 0;
        string res;
        
        for (char& ch : s) {
            if (ch == ')') close++;
        }
        
        for (char& ch : s) {
            if (ch == '(') {
                if (open == close) continue;
                open++;
            } else if (ch == ')') {
                close--;
                if (open == 0) continue;
                open--;
            }
            
            res += ch;
        }
        return res;
    }
};