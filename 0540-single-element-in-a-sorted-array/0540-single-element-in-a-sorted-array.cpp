class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // the single element would be at an even index without its pair next to it
        // elements after it are at even indexes not followed by their pair
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            mid = mid % 2 != 0 ? mid - 1 : mid;
            if (nums[mid] == nums[mid + 1]) {
                low = mid + 2;
            } else {
                high = mid;
            }
        }
        return nums[low];
    }
};