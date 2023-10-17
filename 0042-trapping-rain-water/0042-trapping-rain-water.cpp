class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int left = 0, right = height.size() - 1;
        int maxHeightOnLeft = height[left], maxHeightOnRight = height[right];
        
        while (left < right) {
            if (maxHeightOnLeft <= maxHeightOnRight) { // no water can be trapped at endpoints
                left++;
                maxHeightOnLeft = max(maxHeightOnLeft, height[left]);
                res += maxHeightOnLeft - height[left];
            } else {
                right--;
                maxHeightOnRight = max(maxHeightOnRight, height[right]);
                res += maxHeightOnRight - height[right];                
            }
        }
        return res;
    }
};