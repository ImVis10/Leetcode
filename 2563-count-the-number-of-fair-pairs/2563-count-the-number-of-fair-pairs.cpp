class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return getNumPairSumLessThanTarget(nums, upper + 1) - getNumPairSumLessThanTarget(nums, lower);
    }
private: long long getNumPairSumLessThanTarget(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    long long res = 0;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum < target) {
            res += (right - left); // not right - left + 1 because we need the number of pairs, not the length of the subarray
            left++;

        } else {
            right--;
        }
    }
    return res;
}
};