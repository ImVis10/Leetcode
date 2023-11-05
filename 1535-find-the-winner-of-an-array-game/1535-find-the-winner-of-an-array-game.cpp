class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        
        if (k == 1) return arr[0] > arr[1] ? arr[0] : arr[1];
        
        if (k >= n) return *max_element(arr.begin(), arr.end());
        
        int currWinner = arr[0], winCount = 0;
        
        for (int i = 1; i < n; i++) {
            if (currWinner > arr[i]) winCount++;
            else {
                currWinner = arr[i];
                winCount = 1;
            }
            if (winCount == k) return currWinner;
        }
        return currWinner;
    }
};