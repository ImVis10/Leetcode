class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int res = 0;
        sort(ages.begin(), ages.end());
        for (int& age : ages) {
            auto idx1 = upper_bound(ages.begin(), ages.end(), age) - ages.begin();
            auto idx2 = upper_bound(ages.begin(), ages.end(), (0.5 * age) + 7) - ages.begin();
            if (idx1 > idx2) res += idx1 - idx2 - 1;
        }
        return res;
        
    }
};