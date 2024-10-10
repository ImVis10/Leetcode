class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size(), res = 0;
        // we are checking for the values to the right of a number in the array
        // and we need the values on the right to be greater than or equal to the number
        // so if we have maximum value in the right of a number for every number, max width of the ramp can be found in single pass
        // eg: arr = [6, 0, 8, 2, 1, 5] , maxRight = [8,8,8,5,5,5]
        vector<int> maxRight(n);
        int prevMax = 0;
        for (int i = n - 1; i >= 0; i--) { // starting from the end, just so that it makes the job of calculating max val to the right of every number easier
            maxRight[i] = max(nums[i], prevMax);
            prevMax = maxRight[i];
        }
        
        int i = 0;
        for (int j = 0; j < n; j++) {
            while (nums[i] > maxRight[j]) {
                i++;
            }
            res = max(res, j - i);
        }
        
        return res;
    }
};