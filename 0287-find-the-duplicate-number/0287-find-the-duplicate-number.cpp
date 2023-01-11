class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Make a linked list sort of data structure based on the numbers in nums
        // element points to its index
        // The linked list sort of DS should contain the elements of nums and each element 'i' should point to the the element at index = i
        // Then apply Floyd's cycle detection algo on the linked list
        // Origin of cycle is the result i.e. Duplicate
        // More at: https://imgur.com/a/WJfYYmo
        int slow = 0, fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                break;
            }
        }
        
        int secondSlow = 0;
        
        while (true) {
            slow = nums[slow];
            secondSlow = nums[secondSlow];
            if (slow == secondSlow) {
                return slow;
            }
        }
    }
};