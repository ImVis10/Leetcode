class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end()), right = accumulate(weights.begin(), weights.end(), 0);
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (feasible(weights, mid, days)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
private:
    bool feasible(vector<int>& weights, int capacity, int expectedDays) {
        int daysTaken = 1;
        int total = 0;
        for (int weight : weights) {
            total += weight;
            if (total > capacity) {
                total = weight;
                daysTaken++;
                if (daysTaken > expectedDays) {
                    return false;
                }
            }
        }
        return true;
    }
};