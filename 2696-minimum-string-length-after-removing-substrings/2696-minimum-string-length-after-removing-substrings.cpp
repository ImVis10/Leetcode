class Solution {
public:
    int minLength(string s) {
        stack<char> stk;
        for (char& ch : s) {
            if (!stk.empty()) {
                if (ch == 'B' and stk.top() == 'A') stk.pop();
                else if (ch == 'D' and stk.top() == 'C') stk.pop();
                else stk.push(ch);
            } else {
                stk.push(ch);
            }
        }
        return stk.size();
    }
};