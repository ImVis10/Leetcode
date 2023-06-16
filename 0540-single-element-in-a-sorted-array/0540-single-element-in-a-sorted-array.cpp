class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // single element would be at even index
        int low = 0, high = nums.size() - 1;
        if (nums.size() == 1) {
            return nums[0];
        }
        while (low <= high) {
            int mid = low + (high - low) / 2;
            mid = mid % 2 == 0 ? mid : mid - 1;
            if (nums[mid] == nums[mid + 1]) {
                low = mid + 2;
            } else {
                high = mid - 1;
            }
        }
        return nums[low];
    }
};