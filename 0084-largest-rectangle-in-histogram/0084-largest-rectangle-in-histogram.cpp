class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> stack;
        
        for (int i = 0; i < heights.size(); i++) {
            int start = i;
            while (!stack.empty() && stack.top().second > heights[i]) { // Top of the stack always = highest bar until that moment.
                int index = stack.top().first; // index of the previous higher bar
                int height = stack.top().second; // height of the previous higher bar
                stack.pop();
                maxArea = max(maxArea, height * (i - index)); // width = i - index
                start = index; // as the bar at height[i] can be extended back until this index with height = heights[i]
            }
            stack.push({start, heights[i]});
        }
        
        while (!stack.empty()) {
            int height = stack.top().second;
            int width = heights.size() - stack.top().first;
            stack.pop();
            maxArea = max(maxArea, height * width);
        }
        
        return maxArea;
    }
};