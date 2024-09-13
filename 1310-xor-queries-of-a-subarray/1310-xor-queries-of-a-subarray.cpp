class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> res;
        
        for (auto& vec : queries) {
            int xorVal = 0;
            for (int i = vec[0]; i <= vec[1]; i++) {
                xorVal ^= arr[i];
            }
            res.push_back(xorVal);
        }
        return res;
    }
};