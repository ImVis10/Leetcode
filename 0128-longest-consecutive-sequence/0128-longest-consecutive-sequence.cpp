class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // This approach takes o(n log n) which is not what is expected in the problem statement. So optimizing this to O(n), to increase time complexity space complexity needs to be increased most of the times as there is always a trade off between the two.
        // if (nums.size() == 0) {
        //     return 0;
        // }
        // sort(nums.begin(), nums.end());
        // int maxSeq = 1, currSeq = 1;
        // for (int i = 1; i < nums.size(); i++) {
        //     if (nums[i] != nums[i - 1]) {
        //         if (nums[i] == nums[i - 1] + 1) {
        //             currSeq += 1;
        //         } else {
        //             maxSeq = max(currSeq, maxSeq);
        //             currSeq = 1; // reset the length of the current sequnce formed
        //         }
        //     }
        // }
        // return max(currSeq, maxSeq);
        if (nums.size() == 0) {
            return 0;
        }
        unordered_set<int> set(nums.begin(), nums.end());
        int maxSeq = 1, currSeq = 1;
        for (int num : nums) {
            if (!set.count(num - 1)) { // if num - 1 is not present in the set
                int currNum = num;
                currSeq = 1;
            
                while (set.count(currNum + 1)) {
                    currNum += 1;
                    currSeq += 1;
                }
                maxSeq = max(currSeq, maxSeq); 
            }    
        }
        return maxSeq;
    }
};