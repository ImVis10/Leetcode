class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return getStringAfterBackspace(s) == getStringAfterBackspace(t);
    }
private:
    string getStringAfterBackspace(string s) {
        stack<char> stk;
        string res = "";
        for (auto& ch : s) {
            if (!stk.empty() && ch == '#') stk.pop();
            else if (stk.empty() && ch == '#') continue;
            else stk.push(ch);
        }
        
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        cout << res << endl;
        return res;
    }
};