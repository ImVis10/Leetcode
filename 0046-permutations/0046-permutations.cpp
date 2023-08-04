// class Solution {
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<int> perm;
//         vector<vector<int>> res;
//         vector<bool> picked(nums.size(), false);
//         recurse(nums, perm, picked, res);
//         return res;
//     }
// private:
//     void recurse(vector<int> nums, vector<int> perm, vector<bool>& picked, vector<vector<int>>& res) {
//         if (perm.size() == nums.size()) {
//             res.push_back(perm);
//             return;
//         }
        
//         for (int i = 0; i < nums.size(); i++) {
//             if (!picked[i]) {
//                 picked[i] = true;
//                 perm.push_back(nums[i]);
//                 recurse(nums, perm, picked, res);
            
//                 perm.pop_back(); // backtrack 
//                 picked[i] = false;
//             }
//         }
//     }
// };

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> res;
      recurse(0, nums, res);
      return res;
    }
    
private:
    void recurse(int idx, vector<int>& nums, vector<vector<int>>& res) {
      if (idx == nums.size()) {
        res.push_back(nums);
        return;
      }

      for (int i = idx; i < nums.size(); i++) {
        swap(nums[i], nums[idx]);
        recurse(idx + 1, nums, res);
        swap(nums[i], nums[idx]); // backtrack
      }
    }
};