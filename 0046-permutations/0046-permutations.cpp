class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> res;
      recurse(0, nums, res);
      return res;
    }
    
private:
    void recurse(int idx, vector<int>& arr, vector<vector<int>>& res) {
      if (idx == arr.size()) {
        res.push_back(arr);
        return;
      }

      for (int i = idx; i < arr.size(); i++) {
        swap(arr[i], arr[idx]);
        recurse(idx + 1, arr, res);
        swap(arr[i], arr[idx]); // to take the array back to its original
      }
    }
};