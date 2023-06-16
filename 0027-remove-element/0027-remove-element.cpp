class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
        // return nums.size();
        int n = nums.size();
        int i = 0;
        
        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n - 1];
                n--;
            } else {
                i++;
            }
        }
        return n;
    }
};