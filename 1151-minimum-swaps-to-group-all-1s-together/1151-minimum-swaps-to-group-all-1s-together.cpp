class Solution {
public:
    int minSwaps(vector<int>& data) {
        int n = data.size();
        int numOnes = count_if(data.begin(), data.end(), [](int num) {
            return num == 1;
        });
        
        // the output after swap would have a window of length numOnes with all 1s
        // check all the windows of length numOnes
        // find the window with maximum 1s
        // number of swaps needed is numOnes - maxNumOnesInWindow
        
        // corner cases
        if (numOnes <= 1 || numOnes == data.size()) return 0;
        
        int numOnesInWindow = 0, maxNumOnesInWindow = 0;
        for (int i = 0, j = 0; j < n; j++) { // sliding window [i... j]
            if (data[j] == 1) numOnesInWindow++;
            if (j - i + 1 == numOnes) { // current window ends.. next window starts
                maxNumOnesInWindow = max(maxNumOnesInWindow, numOnesInWindow);
                if (data[i++] == 1) numOnesInWindow--; // as the current window ends, update the numOnes in the current window i.e numOnesInWindow
            }
        }
        return numOnes - maxNumOnesInWindow;
    }
};