class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        vector<int> temp = arr;
        int n = temp.size();
        
        sort(temp.begin(), temp.end());
        
        if (temp[0] > 1) temp[0] = 1;
        
        for (int i = 1; i < n; i++) {
            if (abs(temp[i] - temp[i - 1]) <= 1) continue;
            else temp[i] = 1 + temp[i - 1];
        }
        return temp[n - 1];
    }
};