class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int res = 1;
        long long sum = 0;
        
        for (int low = 0, high = 0; high < n; high++) {
            sum += nums[high];
            // Check if the count of increments needed to make all elements in the current window equal to nums[high] is more than k
            while (static_cast<long long> (nums[high]) * (high - low + 1) - sum > k) {
                sum -= nums[low++];
            }
            res = max(res, high - low + 1);
        }
        return res;
    }
};