class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> stack;
        int res =  0;
        
        for (string op : operations) {
            if (op == "+") {
                int oldTop = stack.top();
                stack.pop();
                
                int newTop = stack.top();
                
                stack.push(oldTop);
                stack.push(oldTop + newTop);
                
                res += oldTop + newTop;
            } else if (op == "D"){
                res += (stack.top() * 2);
                stack.push(2 * stack.top());
            } else if (op == "C"){
                res -= stack.top();
                stack.pop();
            } else {
                res += stoi(op);
                stack.push(stoi(op));
            }
        }
        
        return res;
        
        
    }
};
