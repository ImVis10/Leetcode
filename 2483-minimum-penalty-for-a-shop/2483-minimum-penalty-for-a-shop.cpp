class Solution {
public:
    int bestClosingTime(string customers) {
        // int close = 0;
        // int res = INT_MAX;
        // int pos = -1;
        // while (close <= customers.length()) {
        //     int pen = 0;
        //     for (int i = 0; i < customers.length(); i++) {
        //         if (close > i) {
        //             if (customers[i] == 'N') {
        //                 pen++;
        //             }
        //         } else {
        //             if (customers[i] == 'Y') {
        //                 pen++;
        //             }
        //         }
        //     }
        //     if (pen < res) {
        //         res = pen;
        //         pos = close;
        //     } 
        //     close++; 
        // }
        // return pos;
        
        // GETTING TLE
        
        // so should store the computed results
        
        int n = customers.length();
        vector<int> prefixN(n + 1, 0);
        vector<int> suffixY(n + 1, 0);
        
        for (int i = 1; i <= n; i++) { // shop is open
            prefixN[i] = prefixN[i - 1];
            if (customers[i - 1] == 'N') { // but no customers visit
                prefixN[i] += 1;
            }
        }
        
        for (int i = n - 1; i >= 0; i--) { // shop is closed
            suffixY[i] = suffixY[i + 1];
            if (customers[i] == 'Y') { // but customers visit
                suffixY[i] += 1;
            }
        }
        
        int minPen = INT_MAX, res = -1;
        
        for (int i = 0; i <= n; i++) {
            int pen = prefixN[i] + suffixY[i];
            if (pen < minPen) {
                minPen = pen;
                res = i;
            }
        }
        return res;
    }
};