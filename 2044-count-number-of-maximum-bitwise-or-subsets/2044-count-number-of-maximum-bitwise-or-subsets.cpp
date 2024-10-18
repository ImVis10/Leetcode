class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for (int num : nums) maxOr |= num;
        return recur(nums, 0, 0, maxOr);
    }
private:
    int recur(vector<int>& nums, int idx, int currOr, int maxOr) {
        if (idx == nums.size()) {
            return currOr == maxOr ? 1 : 0;
        }
        int withCurrNum = recur(nums, idx + 1, currOr | nums[idx], maxOr);
        int withoutCurrNum = recur(nums, idx + 1, currOr, maxOr);
        
        return withCurrNum + withoutCurrNum;
    }
};