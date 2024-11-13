class Solution {
public:
    int rob(vector<int>& nums) {
        int prevPrevMax = 0, prevMax = 0;
        for (int num : nums) {
            int currMax = max(prevPrevMax + num, prevMax);
            prevPrevMax = prevMax;
            prevMax = currMax;
        }
        return prevMax;
    }
};