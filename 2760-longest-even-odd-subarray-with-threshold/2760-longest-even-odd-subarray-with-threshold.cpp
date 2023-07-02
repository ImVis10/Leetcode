class Solution {
public:
    int longestAlternatingSubarray(vector<int>& a, int threshold) {
        int n = a.size();
        int res = 0;
        
        for (int l = 0; l < n; l++) {
            if (a[l] % 2 == 1 || a[l] > threshold) continue;
            int r = l + 1;
            while (r < n && a[r] <= threshold && a[r] % 2 != a[r - 1] % 2) {
                r++;
            }
            res = max(res, r - l);
        }
        return res;
    }
};