class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<vector<int>> ranges;
        
        if (nums.size() == 0) {
            return {{lower, upper}};
        }
        
        if (nums[0] > lower) {
            vector<int> range;
            range.push_back(lower);
            range.push_back(nums[0] - 1);
            ranges.push_back(range);          
        }
        
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] + 1 != nums[i + 1]) {
                vector<int> range;
                range.push_back(nums[i] + 1);
                range.push_back(nums[i  + 1] - 1);
                ranges.push_back(range);
            }
        }
        
        if (nums[n - 1] < upper) {
            vector<int> range;
            range.push_back(nums[n - 1] + 1);
            range.push_back(upper);
            ranges.push_back(range);
        }
        
        return ranges;
    }
};