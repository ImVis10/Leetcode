class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if (k == 0) {
            return nums;
        }
        
        int n = nums.size();
        vector<int> res(n , -1);
        
        if (n < 2 * k + 1) {
            return res;
        }
        
        long long sum = 0;
        int windowSize = 2 * k + 1;
        for (int i = 0; i < windowSize; i++) {
            sum += nums[i];
        }
        
        res[k] = sum / windowSize;
        
        for (int i = windowSize; i < n; i++) {
            sum = sum - nums[i - windowSize] + nums[i];
            res[i - k] = sum / windowSize;
        }
        return res;
    }
};