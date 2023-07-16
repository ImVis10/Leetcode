class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // sliding window
        return helper(nums, k) - helper(nums, k - 1);
    }
private:
    int helper(vector<int>& nums, int k) {        
        int n = nums.size();
        int count = 0, res = 0;
        for (int i = 0, j = 0; j < n; j++) {
            count += nums[j] % 2;
            while (count > k) {
                count -= nums[i++] % 2;
            }
            res += j - i + 1;
        }
        return res;  
    }
};