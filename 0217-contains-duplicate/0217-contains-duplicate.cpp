class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        bool containsDuplicate = false;
        int len = nums.size();
        sort(begin(nums), end(nums));
        for (int i = 0; i < len - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                containsDuplicate = true;
            }
        }
        return containsDuplicate;
    }
};