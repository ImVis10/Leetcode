class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0, majorityCount = 0;
        map<int, int> map;
        for (int num : nums) {
            map[num]++;
            if(map[num] > majorityCount) {
                res = num;
            }
            majorityCount = max(majorityCount, map[num]);
        }
        return res;
    }
};