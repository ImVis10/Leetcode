class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = *max_element(candies.begin(), candies.end());
        
        int n = candies.size();
        vector<bool> res(n);
        
        for (int i = 0 ; i < n; i++) {
            res[i] = candies[i] + extraCandies >= maxCandies ? 1 : 0;
        }
        return res;
    }
};