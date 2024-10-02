class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp(arr.begin(), arr.end());
        sort(temp.begin(), temp.end());
        
        int rank = 1;
        
        unordered_map<int, int> mp; // val -> rank
        
        for (int i = 0; i < temp.size(); i++) {
            if (mp.find(temp[i]) == mp.end()) {
                mp[temp[i]] = rank++;
            }
        }
        vector<int> res;
        
        for (int num : arr) {
            res.push_back(mp[num]);
        }
        return res;
    }
};