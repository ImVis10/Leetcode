class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // IN-PLACE
        if (k == 0) {
            return;
        }
        int n = nums.size();
        // [1,2,3,4,5], k = 2
        // Step 1: Reverse entire array --> [5,4,3,2,1]
        // Step 2: Reverse the sub-array[0..k - 1] --> [4,5,3,2,1]
        // Step 3: Reverse the sub-array[k.. n - 1] --> [4,5,1,2,3]
        k = (k > n) ? k % n : k;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};