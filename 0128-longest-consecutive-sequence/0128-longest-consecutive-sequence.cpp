class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int res = 0, currSeqLen = 0;
        for (int num : nums) {
            if (!(st.find(num - 1) != st.end())) {
                int currSeqStart = num;
                currSeqLen = 1;
                
                while (st.find(currSeqStart + 1) != st.end()) {
                    currSeqStart++;
                    currSeqLen++;
                }
                res = max(res, currSeqLen);
            }
        }
        return res;
    }
};