class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                break;
            }
        }
        while (true);
        
        int secondSlow = 0;
        
        do {
            slow = nums[slow];
            secondSlow = nums[secondSlow];
            if (slow == secondSlow) {
                return slow;
            }
        }
        while (true);
    }
};