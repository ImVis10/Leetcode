class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = *min_element(time.begin(), time.end());
        long long high = low * totalTrips;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (canMakeTotalTrips(time, mid, totalTrips)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
private:
    bool canMakeTotalTrips(vector<int>& time, long long mid, int totalTrips) {
        int tripsMade = 0;
        for (int i = 0; i < time.size(); i++) {
            if (tripsMade < totalTrips) tripsMade += mid / time[i];
        }
        return tripsMade >= totalTrips;
    }
};