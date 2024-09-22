class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r)  {
            int m = l + (r - l) / 2;
            if (nums[m] == target) return m;
            else if (nums[m] >= nums[l]) { // subarray on left to mid is sorted
                if (nums[l] <= target and target < nums[m]) { // target is in the sorted subarray left to mid
                    r = m - 1;
                } else { // target is in the other subarray
                    l = m + 1;
                }
            } else { // subarray on right to mid is sorted 
                if (nums[m] < target and target <= nums[r]) { // target is in the sorted subarray right to mid
                    l = m + 1; 
                } else { // target is in the other subarray
                    r = m - 1;
                }
            }
        }
        return -1;
    }
};