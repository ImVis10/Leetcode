class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        // int n = nums.size();
        // int low = nums[0];
        // for (int i = 1; i < n; i++) {
        //     while (nums[i] != ++low) {
        //         if (--k == 0) {
        //             return low;
        //         }
        //     }
        // }
        // return nums[n - 1] + k;
        
        // USING BINARY SEARCH
        
        int n = nums.size();
        int low = 0, high = n;        
        while (low < high - 1) {
            int mid = low + (high - low) / 2;
            int numMissing = numberOfMissingElementsUntil(mid, nums);
            if (numMissing < k) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return nums[low] + k - numberOfMissingElementsUntil(low, nums);
    }
private:
    int numberOfMissingElementsUntil(int idx, vector<int>& nums) {
        if (idx == 0) {
            return 0;
        }
        int res = nums[idx] - nums[0] - idx;
        return res;
    }
};