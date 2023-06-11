class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        // int maxVal = *max_element(nums.begin(), nums.end());
        // int minVal = *min_element(nums.begin(), nums.end());
        // int res = -1;
        // for (int num : nums) {
        //     if (num != maxVal || num != minVal) {
        //         res = num;
        //         break;
        //     }
        // }
        // return res;
        // if (nums.size() <= 2) {
        //     return -1;
        // }
        // sort(nums.begin(), nums.end());
        // return nums[1];
        
        // Since we need to return any element that is neither a minimum nor a maximum and that the given list is of distinct numers, all we need is to find such                element among the first 3 numbers in the array
        
        if (nums.size() <= 2) {
            return -1;
        }
        
        int minVal = min(nums[0], nums[1]);
        int maxVal = max(nums[0], nums[1]);
        
        if (nums[2] > minVal && nums[2] < maxVal) {
            return nums[2];
        } else if (nums[2] < minVal) {
            return minVal;
        } else {
            return maxVal;
        }


    }
};