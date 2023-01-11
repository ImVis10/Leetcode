class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // h will always be >= len(piles) as in each our only one pile of bananas can be eaten
        int low = 1, high = *max_element(piles.begin(), piles.end());
        
        int k = high; // the maximum that can be eaten in an hour is the pile that has maximum bananas
        // max speed = k / hr
        
        while (low <= high) { // do a binary search to find the correct 'k'
            int mid = low + (high - low) / 2;
            long int numHours = 0;
            
            for (int pile : piles) {
                numHours += ceil((double) pile / mid); // number of hours taken to eat all the bananas
            }
                        
            if (numHours <= h) { // if number of hours to eat all the bananas is <= guard missing time
                high = mid - 1; // then the search space is only till mid - 1;
                k = min(mid, k); // finding minimu 'k' 
            } else { // if number of hours to eat all the bananas is > guard msiing time
                low = mid + 1; // then the search space starts from mid + 1
            }
        }
        return k;
    }
};