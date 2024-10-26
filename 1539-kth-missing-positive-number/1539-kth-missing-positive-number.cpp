class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // ideally, when no numbers are missing the array should be [1, 2, 3, ....]
        // so at 0th position, 1 must be present. at 1st position, 2 must be present..
        // so at ith position, i + 1 must be present
        // no. of integers missing at position i is arr[i] - (i + 1)
        int n = arr.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left / 2);
            if (arr[mid] - (mid  +1) < k) { // no. of missing ints is less than k, so move right
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left + k;

    }
};