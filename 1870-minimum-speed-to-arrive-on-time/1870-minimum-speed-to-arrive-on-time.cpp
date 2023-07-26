class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double timeRequired) {
        // Approach from DISCUSS section
        // result can be in the range of [1, 10^7]
        // checking for each speed is not optimal
        // so can do Binary Search
        int low = 0, high = pow(10, 7);
        int res = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            double timeTaken = timeToTravel(dist, mid);
            
            if (timeTaken <= timeRequired) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }
private:
    double timeToTravel(vector<int>& dist, int speed) {
        int n = dist.size();
        double time = 0;
        for (int i = 0; i < n - 1; i++) { // only till n - 2 as there is no need to wait for the time to be rounded off for the last train
            time += ceil((double) dist[i] / speed);
        }
        time += (double) dist[n - 1] / speed; // for the last train
        return time;
    }
};