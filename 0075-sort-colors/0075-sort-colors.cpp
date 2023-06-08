class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Dutch National Flag problem
        int low = 0, mid = 0, high = nums.size() - 1;
        
        while (mid <= high) { // as long as there is unsorted section
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[high], nums[mid]);
                high--;
            }
        }
    }
};