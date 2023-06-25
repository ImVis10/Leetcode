class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<vector<int>> ranges;
        
        if (nums.size() == 0) {
            return {{lower, upper}};
        }
        
        if (nums[0] > lower) {
            ranges.push_back({lower, nums[0] - 1});          
        }
        
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] + 1 != nums[i + 1]) {
                ranges.push_back({nums[i] + 1, nums[i + 1] - 1});
            }
        }
        
        if (nums[n - 1] < upper) {
            ranges.push_back({nums[n - 1] + 1, upper});
        }
        
        return ranges;
    }
};