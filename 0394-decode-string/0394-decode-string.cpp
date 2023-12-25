class Solution {
public:
    string decodeString(string s) {
        stack<char> stack;
        string res;
        
        for (char ch : s) {
            if (ch != ']') stack.push(ch);
            else {
                string alpha = "";
                while (stack.top() != '[') {
                    alpha = stack.top() + alpha;
                    stack.pop();
                }
                stack.pop(); // to pop '['
                int freq = 0, base = 1;
                while (!stack.empty() and isdigit(stack.top())) {
                    freq += (stack.top() - '0') * base;
                    base *= 10;
                    stack.pop();
                }
                cout << alpha << " " << freq << endl;
                while (freq--) {
                    for (char ch : alpha) stack.push(ch);
                }
            }
        }
        cout << stack.size() << endl;
        while (!stack.empty()) {
            res = stack.top() + res;
            stack.pop();
        }
        return res;
    }
};