class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        recurse(0, 0, n, "", res);
        return res;
    }
private:
    void recurse(int open, int close, int n, string par, vector<string>& res) {
        if (open == n && open == close) {
            res.push_back(par);
            return;
        }
        
        if (open < n) recurse(open + 1, close, n, par + '(', res);
        if (close < open) recurse(open, close + 1, n, par + ')', res);
    }
};