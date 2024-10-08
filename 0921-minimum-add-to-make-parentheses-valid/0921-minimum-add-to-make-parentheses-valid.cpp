class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, unbalancedOpen = 0, close = 0, unbalancedClose = 0;
        int n = s.length();
        for (char ch : s) {
            if (ch == '(') open++;
            else {
                if (open == 0) unbalancedClose++;
                else open--;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            char ch = s[i];
            if (ch == ')') close++;
            else {
                if (close == 0) unbalancedOpen++;
                else close--;
            }
        }
        return unbalancedOpen + unbalancedClose;
    }
};