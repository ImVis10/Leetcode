class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size() == 1 && isNumber(tokens[0])) {
            return stoi(tokens[0]);
        }
        int res = 0;
        int num1 = 0, num2 = 0;
        stack<int> stack;
        for (string str : tokens) {
           if (isNumber(str)) {
               stack.push(stoi(str));
           } else {
                num2 = stack.top();
                stack.pop();
                num1 = stack.top();
                stack.pop();
                if (str[0] == '+') {
                    res = num1 + num2;
                } else if (str[0] == '-') {
                    res = num1 - num2;
                } else if (str[0] == '*') {
                    res = num1 * num2;
                } else {
                    res = num1 / num2;
                }
                // switch(str[0]) {
                //     case '+':
                //         res = num1 + num2;
                //         break;
                //     case '-':
                //         res = num1 - num2;
                //         break;
                //     case '*':
                //         res = num1 * num2;
                //         break;
                //     case '/':
                //         res = num1 / num2;
                // }
               stack.push(res);
           } 
        }
        return res;
    }
    
private:
    bool isNumber(const std::string & s)
    {
        if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

        char * p;
        strtol(s.c_str(), &p, 10);

        return (*p == 0);
}
};