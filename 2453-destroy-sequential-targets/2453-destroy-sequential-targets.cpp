class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        // common difference of AP is space here
        // numbers having same remainder when divided by space can be expressed in 'num + c * space'
        // eg: [1, 3, 99], space = 2. All have remainder = 1. So 1 + 0(2) = 1, 1 + 1(2) = 3, 1 + 49(2) = 99
        // so let's keep track of remainders of each element
        unordered_map<int, vector<int>> map;
        for (auto& num : nums) {
            map[num % space].push_back(num);
        }
        
        int maxCount = 0;
        // now it's just about getting the least value in max sized values
        for (auto& pair : map) {
            if (pair.second.size() > maxCount) maxCount = pair.second.size();
        }
        int res = INT_MAX;
        for (auto& pair : map) {
            if (pair.second.size() == maxCount) {
                for (auto& num : pair.second) res = min(res, num);
            }
        }
        return res;
    }
};