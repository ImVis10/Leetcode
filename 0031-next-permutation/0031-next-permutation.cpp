class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int dipAt = -1;
        int n = nums.size();
        
        // find the dip (from the back)
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                dipAt = i;
                break;
            }
        }
        
        if (dipAt == -1) { // if no dip (from the back), it means that we're already the last permutation as the array is sorted (in non-decreasing order) completely from the back
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // swap the element at dip with the element just greater than it (from the back)
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > nums[dipAt]) {
                swap(nums[i], nums[dipAt]);
                break;
            }
        }
        
        // Reverse the rest of the array (from the dip + 1 to end)
        reverse(nums.begin() + dipAt + 1, nums.end());
    }
};