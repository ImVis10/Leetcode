class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        int open = 0;
        // to find extra closed braces
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') open++;
            else if (s[i] == ')') {
                if (open == 0) s[i] = '$'; 
                else open--;
            }
        }
        
        // to find extra open braces
        int close = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')') close++; 
            else if (s[i] == '(') {
                if (close == 0) s[i] = '$';
                else close--;
            }
        }
        string res;
        for (char ch : s) {
            if (ch != '$') {
                res += ch;
            }
        }
        return res;
    }
};