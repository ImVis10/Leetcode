class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // same as twosum, here the target is zero and there can be more than one answer, we need to find all the unique triplets that sum to 0. Solution shouldn't contain duplicate triplets.
        int target = 0;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (!(nums[i] > 0)) { // as the array is sorted, remaining values can't be summed to 0.
                if (i == 0 || nums[i] != nums[i - 1]) { // inequality check to eliminate duplicates
                    twoSum(nums, i, res, target);
                }
            }
        }
        return res;
        
    }
    
    void twoSum(vector<int> &nums, int i, vector<vector<int>> &res, int target) {
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[left] + nums[right] + nums[i];
            if (sum == target) {
                res.push_back({nums[i], nums[left++], nums[right--]});
                while (left < right && nums[right] == nums[right + 1]) {
                    right--;
                }
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }
};