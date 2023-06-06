class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
//         sort(arr.begin(), arr.end());
        
//         int diff = arr[1] - arr[0];
        
//         int n = arr.size();
        
//         for (int i = 2; i < n; i++) {
//             if (diff != arr[i] - arr[i - 1]) {
//                 return false;
//             }
//         }
//         return true;
        
        //  EFFICIENT APPROACH
        int minVal = *min_element(arr.begin(), arr.end());
        int maxVal = *max_element(arr.begin(), arr.end());
         
        int n = arr.size();
        
        if ((maxVal - minVal) % (n - 1) != 0)
            return false;
        
        int diff = (maxVal - minVal) / (n - 1);
        
        int i = 0;
        
        while (i < n) {
            if (arr[i] == (i * diff) + minVal) {
                i++;
            } else if ((arr[i] - minVal) % diff != 0) {
                return false;
            } else {
                int idealPos = (arr[i] - minVal) / diff;
                if (arr[i] == arr[idealPos]) { // for duplicate elements
                    return false;
                }
                swap(arr[i], arr[idealPos]);
            }
        }
        return true;
    }
};