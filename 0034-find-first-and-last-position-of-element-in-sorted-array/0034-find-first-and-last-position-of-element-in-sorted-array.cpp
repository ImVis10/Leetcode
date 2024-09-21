class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = getFirstIndex(nums, target);
        int end = getFirstIndex(nums, target + 1) - 1;
        if (start == nums.size() or nums[start] != target) return {-1, -1};
        return {start, end};
    }
private:
    int getFirstIndex(vector<int>& nums, int target) { // returns index of the first element >= target
        int n = nums.size();
        int low = 0, high = n;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};