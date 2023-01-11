class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // in an hour the monkey can eat at the max 1 pile of bananas
        // a single pile can take multiple hours as well
        // the maximum number of bananas the monkey can eat in an hour = max(piles)
        // so the solution can be in the range [1,2,.., max(piles)]
        
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int res = high;
        
        while (low <= high) {
            int k = low + (high - low) / 2;
            long int numHours = 0;
            
            for(int pile : piles) {
                numHours += ceil((double) pile / k);
            }
            
            if (numHours <= h) {
                res = min(res, k);
                high = k - 1;
            } else {
                low = k + 1;
            }
        }
        return res;
    }
};