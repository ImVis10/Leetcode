class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if (k == 0) { // if window size is zero, average is every element divided by 1, so just return nums
            return nums;
        }
        
        int n = nums.size();
        vector<int> res(n , -1);
        
        int windowSize = 2 * k + 1;

        if (n < windowSize) { // if window size greater than size of nums, diameter goes out of bounds for each element of the array
            return res;
        }
        
        long long sum = 0;
        for (int i = 0; i < windowSize; i++) { // first window
            sum += nums[i];
        }
        
        res[k] = sum / windowSize;
        
        for (int i = windowSize; i < n; i++) {
            sum = sum - nums[i - windowSize] + nums[i]; // subtract the first element of previous window and add the new element in the current window
            res[i - k] = sum / windowSize;
        }
        return res;
    }
};