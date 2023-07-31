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
        int low = 0, high = n - 1;        
        while (low < high) {
            int mid = high - (high - low) / 2;
            int numMissing = numberOfMissingElementsUntil(mid, nums);
            if (numMissing < k) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return nums[0] + k + low;
    }
private:
    int numberOfMissingElementsUntil(int idx, vector<int>& nums) {
        int res = nums[idx] - nums[0] - idx;
        return res;
    }
};