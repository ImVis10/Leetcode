class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        int bk_pnt = -1;
        
        // Find the breaking point i.e. where the dip is
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                bk_pnt = i;
                break;
            }
        }
        
        // if input is already the last permutation, just reverse the input
        if (bk_pnt == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // find the element to swap with at the breaking point
        for (int i = n - 1; i > bk_pnt; i--) {
            if (nums[i] > nums[bk_pnt]) {
                swap(nums[i], nums[bk_pnt]);
                break;
            }
        }
        
        // reverse the rest of the array i.e. after the breaking point
        reverse(nums.begin() + bk_pnt + 1, nums.end());
    }
};