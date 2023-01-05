class Solution {
public:
    int trap(vector<int>& height) {
        /**Amount of water trapped in each position i: min(maximum height on the left, maximum height on the right) - height[i]**/
        // Note: Width of each bar is 1
    //     int res = 0;
    //     int len = height.size();
    //     for (int i = 1; i < len - 1; i++) {
    //         int maxHeightOnLeft = 0, maxHeightOnRight = 0;
    //         for (int j = i; j >= 0; j--) {
    //             maxHeightOnLeft = max(maxHeightOnLeft, height[j]);
    //         }
    //         for (int j = i ; j < len; j++) {
    //             maxHeightOnRight = max(maxHeightOnRight, height[j]);
    //         }
    //         res += min(maxHeightOnLeft, maxHeightOnRight) - height[i];
    //     }
    //     return res;
    // }
    // but this takes O(n^2) as we iterate right and left of all the elements in the array i.e. for each element we iterate n - 1 times n*(n - 1) ~ O(n^2).
    // Getting TLE. So should use 2 pointers efficiently now. Can't move both the pointers everyt time.
    int res = 0;
    int left = 0, right = height.size() - 1;
    int maxHeightOnLeft = height[left], maxHeightOnRight = height[right];
    while (left < right) {
        if (maxHeightOnLeft < maxHeightOnRight) { // at each point only minimum of max heights on either of the directions is considered.
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