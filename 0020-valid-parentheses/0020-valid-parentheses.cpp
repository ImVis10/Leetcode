class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2 != 0) return false;
        
        stack<char> st;
        
        for (char ch : s) {
            if (st.empty()) st.push(ch);
            else if (ch == ')' && st.top() == '(' || ch == '}' && st.top() == '{' || ch == ']' && st.top() == '[') st.pop();
            else st.push(ch);
        }
        return st.empty();
    }
};