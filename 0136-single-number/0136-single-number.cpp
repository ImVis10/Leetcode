class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        
        for (int num : nums) {
            res = res ^ num; // a xor a  = 0, 0 xor a = a, 
        }
        return res;
    }
};