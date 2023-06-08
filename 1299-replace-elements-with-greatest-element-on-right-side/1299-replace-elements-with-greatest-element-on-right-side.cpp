class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int maxVal = arr[n - 1];
        arr[n -  1] = -1;
        for (int i = n - 2; i >= 0; i--) {
            int temp = arr[i]; // store the current element before modifying it
            arr[i] = maxVal; // update the current element to the greatest element encountered so far (from the right)
            maxVal = max(maxVal, temp); // update the maxVal to greater number if it is greater than the current element
        }
        return arr;
    }
};