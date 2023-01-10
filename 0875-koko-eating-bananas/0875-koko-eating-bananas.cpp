class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // h will always be >= len(piles) as in each our only one pile of bananas can be eaten
        // int low = 1, high = *max_element(piles.begin(), piles.end());
        int low = 1;
        int high = 0;
        
         for (int pile : piles) {
            high = max(high, pile);
        }
        
        int k = high; // the maximum that can be eaten in an hour is the pile that has maximum bananas
        // max speed = k / hr
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long int numHours = 0;
            
            for (int pile : piles) {
                numHours += ceil((double) pile / mid);
            }
                        
            if (numHours <= h) {
                k = min(mid, k);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return k;
    }
};