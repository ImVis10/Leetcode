class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        int res = 0, w, h;
        
        stack<int> stack;
        
        for (int i = 0; i <= n; i++) {
            while (!stack.empty() && (i == n || heights[i] < heights[stack.top()])) {
                h = heights[stack.top()];
                stack.pop();
                w = stack.empty() ? -1 : stack.top();
                // area = h * (i - w - 1)
                res = max(res, h * (i - w - 1));
            }
            stack.push(i);
        }
        return res;
    }
};