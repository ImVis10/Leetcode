class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> minutes;
        for (string& s : timePoints) {
            int hh = stoi(s.substr(0, 2));
            int mm = stoi(s.substr(3, 2));
            minutes.push_back(hh * 60 + mm);
        }
        sort(minutes.begin(), minutes.end());
        int res = INT_MAX;
        for (int i = 0; i < n - 1; i++) {
            res = min(res, minutes[i + 1] - minutes[i]);
        }
        // edge case
        // time from 12 AM to first element and last element to 12 AM
        int firstAndLast = minutes[0] + (24 * 60 - minutes[n - 1]);
        return min(res, firstAndLast);
    }
};