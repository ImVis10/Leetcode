class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // sliding window using atmost helper
        return helper(nums, k) - helper(nums, k - 1);
    }
private:
    int helper(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0, count = 0;
        unordered_map<int, int> map;
        for (int i = 0, j = 0; j < n; j++) {
            if (map[nums[j]]++ == 0) count++;
            while (count > k) {
                if (--map[nums[i++]] == 0) count--;
            }
            res += j - i + 1;
        }
        return res;
    }
};