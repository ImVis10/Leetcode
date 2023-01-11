class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int res = nums[low];
        
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