class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prodBefore = 1, prodAfter = 1;
        vector<int> res(n , 1);
        
        for (int i = 1; i < n; i++) {
            prodBefore *= nums[i - 1];
            res[i] = prodBefore;
        }
        
        for (int i = n - 2; i >= 0; i--) {
            prodAfter *= nums[i + 1];
            res[i] *= prodAfter;
        }
        
        return res;
    }
};