class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        
        vector<int> heights(cols);
        
        int res = INT_MIN;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '0') heights[j] = 0;
                else heights[j]++;
            }
            res = max(res, largestRectangleArea(heights));
        }
        return res;
    }
    
private:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> stack; // starting index of histogram, height of the histogram
        
        for (int i = 0; i < heights.size(); i++) {
            int start = i; // start index of the histogram under consideration
            while (!stack.empty() && stack.top().second > heights[i]) { // Top of the stack always = highest bar until that moment.
                int index = stack.top().first; // index of the previous higher bar
                int height = stack.top().second; // height of the previous higher bar
                stack.pop(); // pop when height is less than the previous
                maxArea = max(maxArea, height * (i - index)); // width = i - index
                start = index; // as the bar at height[i] can be extended back until this index where height <= heights at previous indices
            }
            stack.push({start, heights[i]});
        }
        
        while (!stack.empty()) { // for the remaining elements in stack, we check the area for each of them
            int height = stack.top().second;
            int width = heights.size() - stack.top().first;
            stack.pop();
            maxArea = max(maxArea, height * width);
        }
        
        return maxArea;
    }
};