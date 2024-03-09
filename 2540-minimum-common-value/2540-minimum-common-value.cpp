class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int res = -1;
        int i = 0, j = 0;
        int m = nums1.size(), n = nums2.size();
        
        while (i < m and j < n) {
            if (nums1[i] == nums2[j]) {
                res = nums1[i];
                break;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        
        return res;
    }
};