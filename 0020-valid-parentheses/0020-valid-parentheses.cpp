class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (char ch : s) {
            if (stack.empty()) {
                stack.push(ch);
            } else if (stack.top() == '(' && ch == ')' || stack.top() == '{' && ch == '}' || stack.top() == '[' && ch == ']') {
                stack.pop();
            } else {
                stack.push(ch);
            }
        }
        return stack.empty();
    }
};