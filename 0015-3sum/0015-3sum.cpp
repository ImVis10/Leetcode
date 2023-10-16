class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size(), target = 0;
        vector<vector<int>> res;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0) {
                if (i == 0 || nums[i] != nums[i - 1]) {
                    twoSum(nums, i, res, target);
                }                
            }

        }
        return res;
    }
private:
    void twoSum(vector<int>& nums, int idx, vector<vector<int>>& res, int target) {
        int low = idx + 1, high = nums.size() - 1;
        while (low < high) {
            int sum = nums[idx] + nums[low] + nums[high];
            if (sum == target) {
                res.push_back({nums[idx], nums[low++], nums[high--]}); // low++ and high-- as we gotta keep moving as there can be multiple answers
                while (low < high && nums[high] == nums[high + 1]) {
                    high--;
                }
            } else if (sum < target) {
                low++;
            } else {
                high--;
            }
        }
    }
};