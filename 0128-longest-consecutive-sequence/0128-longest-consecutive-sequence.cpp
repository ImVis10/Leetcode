class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> set;
        for (int num : nums) {
            set.insert(num);
        }
        
        int res = 0;
        
        for (int num : nums) {
            // check if 'num - 1' is present in the set
            if (!set.count(num - 1)) {
                int currNum = num;
                int currSeqLength = 1;
            
                while (set.count(currNum + 1)) { // while the consecutive elements are present
                    currNum += 1;
                    currSeqLength += 1;
                }
                res = max(res, currSeqLength);
            }
        }
        return res;
    }
};