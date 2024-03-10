class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> res;
        for(int num : nums1) {
            mp[num] = 1;
        }
        for (int num : nums2) {
            if (mp.find(num) != mp.end() and mp[num] == 1) {
                res.push_back(num);
                mp[num] = 0;
            }
        }
        return res;
    }
};