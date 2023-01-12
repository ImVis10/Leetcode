class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> stack;
        int maxArea = 0;
        
        for(int i = 0; i < heights.size(); i++) {
            int startIndex = i;
            while (!stack.empty() && stack.top().second > heights[i]) {
                int index = stack.top().first;
                int height = stack.top().second;
                stack.pop();
                startIndex = index; // starting index of the current bar can be extended back as its height is less than its previous one
                maxArea = max(maxArea, height * (i - index));
            }
            stack.push({startIndex, heights[i]});
        }
        
        while (!stack.empty()) {
            int width = heights.size() - stack.top().first;
            int height = stack.top().second;
            stack.pop();
            maxArea = max(maxArea, height * width);
        }
        return maxArea;
    }
};