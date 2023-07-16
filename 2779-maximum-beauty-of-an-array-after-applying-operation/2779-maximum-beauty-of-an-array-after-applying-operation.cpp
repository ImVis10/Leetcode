class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // int n = nums.size();
        // int res = 1;
        // sort(nums.begin(), nums.end());
        // int maxValInRange = 0;
        // for (int start = 0, end = 1; start < n; start++) {
        //     maxValInRange = nums[start] + k;
        //     while (end < n && maxValInRange >= nums[end++] - k) res++;
        //     res = max(res, start - end + 1);
        // }
        // return res;
        
        // VAMSI'S APPROACH
        map<int, int> map;
        for (auto& num : nums) {
            map[num - k] += 1;
            map[num + k + 1] -= 1;
        }
        int sum = 0, res = 0;
        for (auto&[key, val] : map) {
            sum += val;
            res = max(res, sum);
        }
        return res;
    }
};