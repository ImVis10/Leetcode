#include <algorithm>
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res;
        
        int flag = 0;
        int elementToBeDeleted = 0;
        
        set<int> s1(nums1.cbegin(), nums1.cend());
        set<int> s2(nums2.cbegin(), nums2.cend());
        nums1 = vector<int>(s1.cbegin(), s1.cend());
        nums2 = vector<int>(s2.cbegin(), s2.cend());
        
        
        
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] - nums2[j] == 0) {
                    flag = 1;
                    elementToBeDeleted = nums1[i];
                    break;
                }
            }
            if (flag == 1) {
                nums1.erase(remove(nums1.begin(), nums1.end(), elementToBeDeleted), nums1.end());
                nums2.erase(remove(nums2.begin(), nums2.end(), elementToBeDeleted), nums2.end());
                flag = 0;
                i--;
            }
        }
        res.emplace_back(nums1);
        res.emplace_back(nums2);
        
        return res;
    }
};