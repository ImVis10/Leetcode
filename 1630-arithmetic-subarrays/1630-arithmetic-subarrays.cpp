class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size(), m = l.size();
        
        vector<bool> res(m);
        
        for (int i = 0; i < m; i++) {
            vector<int> subarray(nums.begin() + l[i], nums.begin() + r[i] + 1);
            sort(subarray.begin(), subarray.end());
            res[i] = isArithmetic(subarray);
        }
        return res;
    }
private:
    bool isArithmetic(vector<int>& nums) {
        int n = nums.size();
        
        if (n <= 2) return true;
        
        int diff = nums[1] - nums[0];
        
        for (int i = 1; i < n - 1; i++) {
            if (nums[i + 1] - nums[i] != diff) return false;
        }
        
        return true;
    }
};