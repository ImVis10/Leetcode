class Solution {
public:
    void sortColors(vector<int>& nums) {
        // in-place sorting
        // can do bucket sort
//         vector<int> res;
//         int n = nums.size();
        
//         int numZero = 0, numOne = 0, numTwo = 0;
        
//         for (int i = 0; i < n; i++) {
//             if (nums[i] == 0) {
//                 numZero++;
//             } else if (nums[i] == 1) {
//                 numOne++;
//             } else {
//                 numTwo++;
//             }
//         }
        
//         nums.clear();
        
//         for(int i = 0; i < numZero; i++) {
//             nums.emplace_back(0);
//         }
        
//         for(int i = 0; i < numOne; i++) {
//             nums.emplace_back(1);
//         }
        
//         for(int i = 0; i < numTwo; i++) {
//             nums.emplace_back(2);
//         }
        
        int left = 0, curr = 0, right = nums.size() - 1;
        
        /** left --> every index before 'left' is 0, right --> every index after 'right' is 0
        Algo - 'left' group grow to the right from the left of the array,  keep the 'mid' group just after the 'left' group, 'right' group grow to the left from the right of the array.
        Algo indexes 3 locations - rightmost index of the 'left' group, rightmost index of 'mid' group and leftmost index of the 'right' group.
        Elements that are yet to be sorted fall in between mid and right groups.
        At each step, examine the element just after the mid. If it belongs to 'right' group, swap it with the element just before 'right'. If it belongs to 'left' group, swap it with element just after 'left'. If it  belongs to 'mid', leave it as is.
        **/
        
        while (curr <= right) { // until the iteration of curr reaches or crosses leftmost boundary of 2s 
            if (nums[curr] == 0) {
                swap(nums[left], nums[curr]);
                curr++;
                left++; // every index before left has 0
            } else if (nums[curr] == 1) {
                curr++;
            } else {
                swap(nums[curr], nums[right]);
                right--; // every index after right has 1
            }
        }
    }
};