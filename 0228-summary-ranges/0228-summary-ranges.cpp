class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return {};
        }
        vector<string> res;
        bool sameSeq = false;
        res.push_back(to_string(nums[0]));
        for (int i = 1; i < n; i++) {
            if (nums[i] - 1 != nums[i - 1]) { 
                if (res.back() != to_string(nums[i - 1]))
                    res.back() += "->" + to_string(nums[i - 1]);
                res.push_back(to_string(nums[i]));
            } else if (nums[i] - 1 == nums[i - 1] && i == n-1) {
                res.back() += "->" + to_string(nums[i]);
            }
        }
        return res;
    }
};