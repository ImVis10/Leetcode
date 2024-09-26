class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int missing = 0, i = 0;
        for (int num = 1; ; num++) {
            if (i < arr.size() and arr[i] == num) {
                i++;
            } else {
                missing++;
                if (missing == k) {
                    return num;
                }
            }
        }
    }
};