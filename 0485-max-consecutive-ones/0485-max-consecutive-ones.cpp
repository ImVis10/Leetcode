class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int res = 0;
        for (int num : nums) {
            if (num == 1) {
                count++;
                res = max(count, res);
            } else {
                count = 0;
            }
        }
        return res;
    }
};