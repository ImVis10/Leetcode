class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> subRes;
        vector<vector<int>> res;
        vector<bool> picked(nums.size(), false);
        recurse(nums, subRes, res, picked);
        return res;
    }
    
private:
    void recurse(vector<int>& arr, vector<int> subRes, vector<vector<int>>& res, vector<bool> picked) {
      if (subRes.size() == arr.size()) {
        res.push_back(subRes);
        return;
      }

      for (int i = 0; i < arr.size(); i++) {
        if (!picked[i]) {
          subRes.push_back(arr[i]);
          picked[i] = true;
          recurse(arr, subRes, res, picked);

          subRes.pop_back();
          picked[i] = false;
        }
      }
    }
};