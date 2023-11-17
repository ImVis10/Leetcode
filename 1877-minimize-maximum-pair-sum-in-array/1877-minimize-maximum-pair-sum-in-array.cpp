class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int low = 0, high = n - 1;
        
        int res = INT_MIN;
        
        while (low < high) {
            int pairSum = nums[low++] + nums[high--];
            res = max(res, pairSum);
        }
        return res;
    }
};