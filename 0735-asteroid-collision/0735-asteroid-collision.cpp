class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stack;
        for (auto& asteroid : asteroids) {
            int survive = 1;
            while (!stack.empty() && willCollide(stack.top(), asteroid)) { // will collide only when top of the stack moves right and current asteroid moves left
                int top = stack.top();
                if (abs(asteroid) > abs(top)) {
                    stack.pop();
                    continue;
                } else if (abs(asteroid) == abs(top)) {
                    stack.pop();
                }
                survive = 0;
                break;
            }
            
            if (survive) stack.push(asteroid);
        }
        
        vector<int> res(stack.size());
        for (int i = res.size() - 1; i >= 0; i--){
            res[i] = stack.top();
            stack.pop();
        }
        return res;
    }
                
private:
    bool willCollide(int i, int j) {
        return i > 0 && j < 0;
    }
};