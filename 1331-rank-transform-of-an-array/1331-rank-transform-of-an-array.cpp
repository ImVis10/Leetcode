class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp(arr.begin(), arr.end());
        sort(temp.begin(), temp.end());
        
        int rank = 1;
        
        unordered_map<int, int> mp; // val -> rank
        
        for (int num : temp) {
            if (mp.find(num) == mp.end()) {
                mp[num] = rank++;
            }
        }
        vector<int> res;
        
        for (int num : arr) {
            res.push_back(mp[num]);
        }
        return res;
    }
};