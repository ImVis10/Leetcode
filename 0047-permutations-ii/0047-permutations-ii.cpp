class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> subRes;
        set<vector<int>> set;
        vector<bool> picked(nums.size(), false);
        recurse(nums, subRes, set, picked);
        vector<vector<int>> res;
        for (auto it : set) {
            res.push_back(it);
        }
        return res;
    }
    
private:
    void recurse(vector<int>& arr, vector<int> subRes, set<vector<int>>& set, vector<bool> picked) {
      if (subRes.size() == arr.size()) {
        set.insert(subRes);
        return;
      }

      for (int i = 0; i < arr.size(); i++) {
        if (!picked[i]) {
          subRes.push_back(arr[i]);
          picked[i] = true;
          recurse(arr, subRes, set, picked);

          subRes.pop_back();
          picked[i] = false;
        }
      }
    }
};