class Solution {
public:
    bool validPartition(vector<int>& nums) {
        unordered_map<int, bool> cache;
        return recurse(0, nums, cache);
    }
private:
    bool recurse(int idx, vector<int>& nums, unordered_map<int, bool>& cache) {
        if (idx == nums.size()) {
            return true;
        }
        if (cache.count(idx)) {
            return cache[idx];
        }
        bool res = false;
        if (idx < nums.size() - 1 && nums[idx] == nums[idx + 1]) {
            res = recurse(idx + 2, nums, cache);
        }
        if (idx < nums.size() - 2) {
            if ((nums[idx] == nums[idx + 1]) && (nums[idx + 1] == nums[idx + 2]) || (nums[idx] + 1 == nums[idx + 1]) && (nums[idx + 1] == nums[idx + 2] - 1)) {
                res = res || recurse(idx + 3, nums, cache); // recurse() as the second operand as there is no need for a subarray to satisfy more than one condition. 
            }
        }
        cache[idx] = res;
        return res;
    }
};