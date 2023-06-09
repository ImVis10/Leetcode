class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // majority element appears > n/2 times
        // can make use of bitwise operators
        
//         int n = nums.size();
//         int res = 0; // all bits are initially zero
        
//         for (int i = 0; i < 32; i++) {
//             int bit = 1 << i;
//             int currBitCount = 0;
//             for (int num : nums) {
//                 int currBit = num & bit;
//                 if (currBit) { // if the currBit is set
//                     currBitCount++;
//                 } 
//             }
//             if (currBitCount > n / 2) { // set the res to the currBit, so at the end after getting done with all the bits, we'll be making a majority element by ourselves.
//                 res |= bit;
//             }
//         }
//         return res;
        
        // MOORE'S VOTING ALGO
        int cnt = 0;
        int res = nums[0];
        
        for (int num : nums) {
            if (cnt == 0) {
                res = num;
                cnt = 1;
            } else if (num == res) {
                cnt++;
            } else {
                cnt--;
            }
        }
        
        cnt = 0;
        
        for (int num : nums) {
            if (res == num) {
                cnt++;
            }
        }
        
        if (cnt > nums.size() / 2) {
            return res;
        }
        return 0;
    }
};