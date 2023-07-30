class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> set(nums.begin(), nums.end());
        int distinct = set.size(), res = 0;
        
        set.clear();
        
        int start = 0, end = 0;
        while (end < nums.size()) {
            if (set.count(nums[end]) == 0) {
                set.insert(nums[end]);
                distinct -= 1;
            }
            if (end < nums.size() && distinct == 0) {
                res++;
                if (end == nums.size() - 1) {
                    start++;
                    end = start;
                    distinct = set.size();
                    set.clear();
                    continue;
                }
            }
            end++;
        }
        return res;
    }
};