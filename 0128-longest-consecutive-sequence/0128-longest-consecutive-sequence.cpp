class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int maxSeq = 1, currSeq = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                if (nums[i] == nums[i - 1] + 1) {
                    currSeq += 1;
                } else {
                    maxSeq = max(currSeq, maxSeq);
                    currSeq = 1; // reset the length of the current sequnce formed
                }
            }
        }
        return max(currSeq, maxSeq);
    }
};