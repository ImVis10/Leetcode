class Solution {
public:
    int findMin(vector<int>& nums) {
        // O(log n) -- can use binary search
        // the sorted rotated array contains two sub-arrays which are sorted
        // values in the left (1st) sorted sub-array are always > values in right (2nd) sorted sub-array
        // so if we figure out in which sub-array we're in, we can move in the appropriate direction
        // if we're in the left sorted array --> search to the right
        // if we're in the right sorted array --> search to the left
        
        int res = nums[0];
        int low = 0, high = nums.size() - 1;
        
        while (low <= high) {
            if (nums[low] < nums[high]) {
                res = min(nums[low], res);
                break;
            }
            
            int mid = low + (high - low) / 2;
            res = min(nums[mid], res);
            
            if (nums[low] <= nums[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return res;
    }
};