class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subRes;
        recur(nums, 0, subRes, res);
        return res;
    }
private:
    void recur(vector<int>& nums, int idx, vector<int> subRes, vector<vector<int>>& res) {
        if (idx == nums.size()) {
            res.push_back(subRes);
            return;
        }
        subRes.push_back(nums[idx]);
        recur(nums, idx + 1, subRes, res);
        subRes.pop_back();
        recur(nums, idx + 1, subRes, res);
        
    }
};