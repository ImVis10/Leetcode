class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stack;
        for (int i : asteroids) {
            int destroy = 1;
            while (!stack.empty() && hasDiffSign(stack.top(), i)) { // if i and top of stack has different sign, pop the top
                int top = stack.top();
                if (abs(i) > abs(top)) {
                    stack.pop();
                    continue;
                } else if (abs(i) == abs(top)) {
                    stack.pop();
                }
                destroy = 0;
                break;
                
            } 
            if (destroy) {
                stack.push(i);
            }
        }
        
        vector<int> res(stack.size());
        for (int i = res.size() - 1; i >= 0; i--){
            res[i] = stack.top();
            stack.pop();
        }
        return res;
    }
                
private:
    bool hasDiffSign(int i, int j) {
        return i > 0 && j < 0;
    }
};