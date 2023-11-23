class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
//         int n = nums.size(), m = l.size();
        
//         vector<bool> res(m);
        
//         for (int i = 0; i < m; i++) {
//             vector<int> subarray(nums.begin() + l[i], nums.begin() + r[i] + 1);
//             sort(subarray.begin(), subarray.end());
//             res[i] = isArithmetic(subarray);
//         }
//         return res;
//     }
// private:
//     bool isArithmetic(vector<int>& nums) {
//         int n = nums.size();
        
//         if (n <= 2) return true;
        
//         int diff = nums[1] - nums[0];
        
//         for (int i = 1; i < n - 1; i++) {
//             if (nums[i + 1] - nums[i] != diff) return false;
//         }
        
//         return true;
        
        int m = l.size();
        vector<bool> res(m);
        
        for (int i = 0; i < m; i++) {
            unordered_set<int> subarray(nums.begin() + l[i], nums.begin() + r[i] + 1);
            int n = r[i] - l[i] + 1;
            int minVal = *min_element(subarray.begin(), subarray.end());
            int maxVal = *max_element(subarray.begin(), subarray.end());
            
            if (minVal == maxVal) {
                res[i] = true;
                continue;
            }
            
            if ((maxVal - minVal) % (n - 1) != 0) {
                res[i] = false;
                continue;
            }
            
            int diff = (maxVal - minVal) / (n - 1);
            
            res[i] = true;
            
            for (int j = 0; j < n; j++) {
                int expected = minVal + j * diff;
                if (subarray.find(expected) == subarray.end()) {
                    res[i] = false;
                    break;
                }
            }
        }
        return res;
    }
};