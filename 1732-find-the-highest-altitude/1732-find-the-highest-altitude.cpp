class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        
        int maxVal = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += gain[i];
            if (sum > maxVal) {
                maxVal = sum;
            }
        }
        return maxVal;
    }
};