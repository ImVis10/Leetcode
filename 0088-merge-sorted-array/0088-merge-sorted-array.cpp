class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0) {
            nums1 = nums2;
            return;
        }

        vector<int> temp(nums1.begin(), nums1.end());
        
        int i = 0, j = 0, idx = 0;
        
        while (i < m and j < n) {
            if (temp[i] == nums2[j]) {
                nums1[idx++] = temp[i];
                nums1[idx++] = temp[i];
                i++;
                j++;
            } else if (temp[i] < nums2[j]) {
                nums1[idx++] = temp[i];
                i++;
            } else {
                nums1[idx++] = nums2[j];
                j++;
            }
        }

        while (idx < m + n and (i < m or j < n)) {
            if (i < m)
                nums1[idx++] = temp[i++];
            else 
                nums1[idx++] = nums2[j++];
        }
    }
};