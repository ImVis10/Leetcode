class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if (sum % 2) return false; // sum is odd
        
        vector<vector<int>> cache(nums.size(), vector<int>((sum / 2) + 1, -1));
        return recurse(nums.size() - 1, nums, sum / 2, cache);
    }
private:
    int recurse(int idx, vector<int>& arr, int target, vector<vector<int>>& cache) {
        if (idx == 0) return arr[idx] == target;
        if (cache[idx][target] != -1) return cache[idx][target];

        bool noPick = recurse(idx - 1, arr, target, cache);
        bool pick = false;
        if (arr[idx] <= target) pick = recurse(idx - 1, arr, target - arr[idx], cache);
        return cache[idx][target] = pick | noPick;
    }
};