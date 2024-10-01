class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Interview Tip: Whenever you're trying to solve an array problem in place, always consider the possibility of iterating backwards instead of forwards through the array. It can completely change the problem, and make it a lot easier.
        // use the zeroes at the end to store data i.e. overwrite them
        // so start iterating nums1 from m - 1 and nums2 from n - 1
        
        if (m == 0) {
            nums1 = nums2;
            return;
        }
        
        int i = m - 1, j = n - 1;
        for (int p = m + n - 1; p >= 0; p--) {
            if (j < 0) {
                break;
            }
            if (i >= 0 and nums1[i] > nums2[j]) {
                nums1[p] = nums1[i];
                i--;
            } else {
                nums1[p] = nums2[j];
                j--;
            }
        }
    }
};