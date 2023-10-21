class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        
        int start = -1, end = -1;
        
        while (low <= high) {
            int mid = low  + (high - low) / 2;
            if (nums[mid] == target) {
                start = mid, end = mid;
                while (start >= 0 && nums[start] == target) start--;
                while (end < n && nums[end] == target) end++;
                cout << start << " " << end << endl;
                return {start + 1, end - 1};
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return {start, end};
    }
};