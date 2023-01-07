class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // no. of open parentheses  = n, no. of closing parentheses = n
        // add open parentheses only when open < n
        // add closing parentheses only when close < open
        vector<string> res;
        backtrack(0, 0, n, "", res);
        return res;
    }
private:
    void backtrack(int numOpen, int numClose, int n, string str, vector<string> & res) {
        if (numOpen == numClose && numClose == n) {
            res.push_back(str);
            return;
        }
        
        if (numOpen < n) {
            backtrack(numOpen + 1, numClose, n, str + '(', res);
        }
        
        if (numClose < numOpen) {
            backtrack(numOpen, numClose + 1, n, str + ')', res);
        }
    }
};