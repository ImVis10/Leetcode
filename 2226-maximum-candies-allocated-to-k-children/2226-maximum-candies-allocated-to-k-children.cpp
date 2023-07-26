class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        // long long sum = accumulate(candies.begin(), candies.end(), 0);
        // long avg = sum / k;
        // long maxCandyPile = *max_element(candies.begin(), candies.end());
        long low = 0, high = pow(10, 7);
        while (low < high) {
            long sum = 0;
            long mid = low + (high - low + 1) / 2;
            for (auto& candy : candies) {
                sum += candy / mid;
            }
            if (k > sum) high = mid - 1;
            else low = mid;
        }
        return high;
    }
};