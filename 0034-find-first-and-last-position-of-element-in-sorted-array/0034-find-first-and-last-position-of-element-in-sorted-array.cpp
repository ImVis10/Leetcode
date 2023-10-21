class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = getFirstIndexOfFirstElementGreaterThanTarget(nums, target - 0.5);
        int end = getFirstIndexOfFirstElementGreaterThanTarget(nums, target + 0.5);
        if (start == end) return {-1, -1};
        return {start, end - 1};
    }
private:
    int getFirstIndexOfFirstElementGreaterThanTarget(vector<int>& nums, double target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target) low = mid + 1;
            else if (nums[mid] > target) high = mid - 1;
        }
        return low;
    }
};