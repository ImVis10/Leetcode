class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        
        sort(piles.begin(), piles.end());
        
        int res = 0;
        
        int numTurns = n / 3;
        
        int idx = n - 2;
        
        while (numTurns--) {
            res += piles[idx];
            idx -= 2;
        }
        return res;
    }
};