class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> subRes;
        
        printAllSubSequences(0, n, nums, subRes, res);
        return res;
    }
private:
    void printAllSubSequences(int idx, int n, vector<int>& nums, vector<int> subRes, vector<vector<int>>& res) {
        if (idx == n) {
            res.push_back(subRes);
            return;
        }
        subRes.push_back(nums[idx]); // pick
        printAllSubSequences(idx + 1, n, nums, subRes, res);
        
        subRes.pop_back(); // don't pick
        printAllSubSequences(idx + 1, n, nums, subRes, res);
    }
};