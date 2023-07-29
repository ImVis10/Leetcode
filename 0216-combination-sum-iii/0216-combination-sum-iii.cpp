class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> comb;
        vector<vector<int>> res;
        
        vector<int> arr(9);
        iota(arr.begin(), arr.end(), 1);
        
        recurse(0, arr, k, n, comb, res);
        return res;
    }
    
private:
    void recurse(int idx, vector<int>& arr, int numElementsToReachTarget, int target, vector<int> comb, vector<vector<int>>& res) {
        if (numElementsToReachTarget == 0 && target == 0) {
            res.push_back(comb);
            return;
        }
        
         for (int i = idx; i < arr.size(); i++) {
             if (comb.size() > 0 && comb.back() == arr[i]) {
                 continue;
             }
             if (arr[i] > target || numElementsToReachTarget == 0) {
                 break;
             }
             comb.push_back(arr[i]);
             recurse(i + 1, arr, numElementsToReachTarget - 1, target - arr[i], comb, res);
             comb.pop_back();
         }
    }
};