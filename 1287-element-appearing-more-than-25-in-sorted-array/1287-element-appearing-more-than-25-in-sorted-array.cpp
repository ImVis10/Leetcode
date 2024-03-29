class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int target = n / 4;
        
        for (int i = 0; i < n; i++) {
            if (arr[i] == arr[i + target]) return arr[i];
        }
        return -1;
    }
};