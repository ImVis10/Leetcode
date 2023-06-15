class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> positive;
//         vector<int> negative;
        
//         for (int num : nums) {
//             num > 0 ? positive.push_back(num) : negative.push_back(num);
//         }
                
//         for (int i = 0; i < n / 2; i++) {
//             nums[2*i] = positive[i];
//             nums[2*i + 1] = negative[i];
//         }
//         return nums;
        
        // ITERATING ONLY ONCE
        int n = nums.size();
        vector<int> res(n);
        
        int pos = 0, neg = 1;
        
        for (int num : nums) {
            if (num > 0) {
                res[pos] = num;
                pos += 2;
            } else {
                res[neg] = num;
                neg += 2;
            }
        }
        return res;
    }
};