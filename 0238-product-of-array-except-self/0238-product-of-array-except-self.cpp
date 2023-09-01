class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prodLeft = 1, prodRight = 1;
        vector<int> res(nums.size(), 0);
        
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0) {
                prodLeft *= nums[i - 1];
            }
            res[i] = prodLeft;
        }
        
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i < nums.size() - 1) {
                prodRight *= nums[i + 1];
            }
            res[i] *= prodRight;
        }
        return res;
    }
};