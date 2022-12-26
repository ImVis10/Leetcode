class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prod(n, 0);
        int prodBefore = 1, prodAfter = 1;
        
        for (int i = 0; i < n; i++) {
            if (i > 0) {
               prodBefore *= nums[i - 1]; 
            }
            
            prod[i] = prodBefore;
        }
        
        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1) {
               prodAfter *= nums[i + 1]; 
            }
            
            prod[i] *= prodAfter;
        }
        return prod;
    }
};