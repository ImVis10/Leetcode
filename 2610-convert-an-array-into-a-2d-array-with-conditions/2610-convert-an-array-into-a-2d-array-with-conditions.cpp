class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> freq;
        vector<vector<int>> res;
        
        for (int num : nums) {
            int row = freq[num];
            if (res.size() == row) res.push_back({});
            res[row].push_back(num);
            freq[num]++;
        }
        return res;
    }
};