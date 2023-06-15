class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> positive;
        vector<int> negative;
        
        for (int num : nums) {
            num > 0 ? positive.push_back(num) : negative.push_back(num);
        }
                
        for (int i = 0; i < n / 2; i++) {
            nums[2*i] = positive[i];
            nums[2*i + 1] = negative[i];
        }
        return nums;
    }
};