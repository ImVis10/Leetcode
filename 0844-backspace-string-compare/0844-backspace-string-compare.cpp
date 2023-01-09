class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stack1;
        stack<char> stack2;
        
        pushToStack(s, stack1);
        pushToStack(t, stack2);
        
        return getStringFromStack(stack1) == getStringFromStack(stack2);
    }

private:
    void pushToStack(string s, stack<char> &stack) {
        for(char ch : s) {
            if (!stack.empty() && ch == '#') {
                stack.pop();
            } else if (ch != '#') {
                stack.push(ch);
            }
        }
    }
    
    string getStringFromStack(stack<char> &stack) {
        string str;
        while (!stack.empty()) {
            char ch = stack.top();
            str += ch;
            stack.pop();
        }
        return str;
    }
};