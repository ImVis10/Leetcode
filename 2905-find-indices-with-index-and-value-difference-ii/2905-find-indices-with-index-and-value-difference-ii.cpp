class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        set<pair<int, int>> set;
        for (int i = 0; i < n; i++) {
            if (i - indexDifference >= 0) {
                set.insert({nums[i - indexDifference], i - indexDifference});
                
                auto minVal = *set.begin();
                auto maxVal = *set.rbegin();

                if (abs(minVal.first - nums[i]) >= valueDifference) return {minVal.second, i};
                if (abs(maxVal.first - nums[i]) >= valueDifference) return {maxVal.second, i};               
            }
        }
        return {-1, -1};
    }
};