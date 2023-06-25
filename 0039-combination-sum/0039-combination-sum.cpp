class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        vector<vector<int>> res;
        recurse(0, candidates, target, res, comb);
        return res;
    }
    
private:
    void recurse(int idx, vector<int>& nums, int target, vector<vector<int>>& res, vector<int> comb) {
        if (idx == nums.size()) {
            if (target == 0) {
                res.push_back(comb);
            }
            return;
        }
        
        if (nums[idx] <= target) {
            comb.push_back(nums[idx]);
            recurse(idx, nums, target - nums[idx], res, comb);
            comb.pop_back(); // restore the array back to the state from where we have to make recurisve calls again
        }
        recurse(idx + 1, nums, target, res, comb);
    }
};