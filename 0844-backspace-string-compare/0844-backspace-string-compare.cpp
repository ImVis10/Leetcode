class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return getStringAfterBackspace(s) == getStringAfterBackspace(t);
    }
private:
    string getStringAfterBackspace(string s) {
        stack<char> stk;
        for (auto& ch : s) {
            if (!stk.empty() && ch == '#') stk.pop();
            else if (ch != '#') stk.push(ch);
        }
        
        string res = "";
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};