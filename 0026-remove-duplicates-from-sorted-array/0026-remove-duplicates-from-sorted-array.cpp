class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // input array is sorted
        int nextUniqueAt = 1;
        
        for (int i = 1; i < nums.size(); i++) { // starting from index 1 as the element at index 0 will stay the same in the result.
            if (nums[i] != nums[i - 1]) {
                nums[nextUniqueAt] = nums[i];
                nextUniqueAt++;
            }
        }
        return nextUniqueAt;
    }
};