class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // input array is sorted
        int nextUniqueAt = 1;
        for (int i = 1; i < nums.size(); i++) { // starting from index 1 as the the number at index 0 stays the same in the result
            if (nums[i] != nums[i - 1]) { // when its a new number i.e. number is different from previous
                nums[nextUniqueAt] = nums[i]; // Update the duplicate number to the new number
                nextUniqueAt++; // increment the index at which the next new number must be placed
            }
        }
        return nextUniqueAt;
    }
};