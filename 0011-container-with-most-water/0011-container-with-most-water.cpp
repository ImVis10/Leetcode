class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxArea = INT_MIN;
        // set the end points
        int left = 0, right = n - 1;
        while (left < right) {
            int h = min(height[left], height[right]);
            int width = right - left;
            int area = h * width;
            maxArea = max(area, maxArea);
            if (height[left] < height[right]) { // to maximize the area
                left++;
            } else if (height[left] > height[right]) { // to maximize the area
                right--;
            } else {
                left++;
                right--;
            }
        }
        return maxArea;
    }
};