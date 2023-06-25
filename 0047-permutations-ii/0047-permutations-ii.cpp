class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> subRes;
        vector<vector<int>> res;
        unordered_map<int, int> count;
        for (auto num : nums) {
            count[num]++;
        }
        recurse(nums, subRes, res, count);
        return res;
    }
    
private:
    void recurse(vector<int>& arr, vector<int> subRes, vector<vector<int>>& res, unordered_map<int, int> count) {
      if (subRes.size() == arr.size()) {
        res.push_back(subRes);
        return;
      }
      for (auto entry : count) {
          int key = entry.first;
          int value = entry.second;

          if (value == 0) {
              continue;
          }
          subRes.push_back(key);
          count[key]--;
          recurse(arr, subRes, res, count);
          
          subRes.pop_back();
          count[key]++; // take the map back to its initial filled state
      }
    }
};