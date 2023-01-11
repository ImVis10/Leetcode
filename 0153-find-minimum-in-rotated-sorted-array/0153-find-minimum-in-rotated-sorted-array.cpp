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
            if (nums[low] < nums[high]) { // when we reach 2nd sorted array and low, high are at appropriate positions
                res = min(nums[low], res);
                break;
            }
            
            int mid = low + (high - low) / 2;
            res = min(nums[mid], res);
            
            if (nums[mid] >= nums[low]) { // we're in the 1st sorted array, so the result would be in the 2nd sorted array, which is to the right of mid
                low = mid + 1;
            } else { // we're in the 2nd sorted array, so the result might be to the left of mid (if mid falls after the result), so we take the minimum before itself (at line no. 21)
                high = mid - 1;
            }
        }
        return res;
    }
};