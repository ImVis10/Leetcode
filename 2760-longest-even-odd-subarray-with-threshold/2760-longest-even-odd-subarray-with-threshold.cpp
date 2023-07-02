class Solution {
public:
    int longestAlternatingSubarray(vector<int>& a, int threshold) {
//         int n = a.size();
//         int res = 0;
        
//         for (int l = 0; l < n; l++) {
//             if (a[l] % 2 == 1 || a[l] > threshold) continue;
//             int r = l + 1;
//             while (r < n && a[r] <= threshold && a[r] % 2 != a[r - 1] % 2) {
//                 r++;
//             }
//             res = max(res, r - l);
//         }
//         return res;
        
        int n = a.size();
        int cnt = 0, res = 0;
        
        for (int l = 0; l < n; l++) {
            if (a[l] <= threshold) {
                if (cnt != 0) {
                    cnt = a[l] % 2 != a[l - 1] % 2 ? cnt + 1 : 0;
                }  
                if (cnt == 0) {
                    cnt = a[l] % 2 == 0;
                }
            } else {
                cnt = 0;
            }
            res = max(res, cnt);
        }
        return res;
    }
};