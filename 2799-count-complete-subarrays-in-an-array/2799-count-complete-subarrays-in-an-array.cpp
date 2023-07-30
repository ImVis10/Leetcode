class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> set(nums.begin(), nums.end());
        int distinct = set.size(), res = 0;
        
        set.clear();
        
        int temp = distinct;
        
        int i = 0, j = 0;
        while (j < nums.size()) {
            if (set.count(nums[j]) == 0) {
                set.insert(nums[j]);
                distinct -= 1;
            }
            if (j < nums.size() && distinct == 0) {
                if (j == nums.size() - 1) {
                    i++;
                    j = i;
                    set.clear();
                    distinct = temp;
                    res++;
                    continue;
                }
                res++;
            }
            j++;
        }
        return res;
    }
};