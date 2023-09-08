class Solution {
public:
    int maxArea(vector<int>& height) { // two pointer approach.. one at the left and other at the right
        int n = height.size();
        
        int maxArea = INT_MIN;
        
        int left = 0, right = n - 1;
        
        while (left < right) {
            int h = min(height[left], height[right]);
            int w = right - left;
            
            int area = h * w;
            
            maxArea = max(area, maxArea);
            
            if (height[left] < height[right]) left++;
            else right--;
        }
        return maxArea;
    }
};