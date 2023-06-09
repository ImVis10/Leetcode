class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // majority element appears > n/2 times
        // can make use of bitwise operators
        
        int n = nums.size();
        int res = 0;
        
        for (int i = 0; i < 32; i++) {
            int bit = 1 << i;
            int currBitCount = 0;
            for (int num : nums) {
                int currBit = num & bit;
                if (currBit) { // if the currBit is set
                    currBitCount++;
                } 
            }
            if (currBitCount > n / 2) { // set the res to the currBit
                res |= bit;
            }
        }
        return res;
    }
};