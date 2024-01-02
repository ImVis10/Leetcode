class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> freq;
        
        vector<vector<int>> res;
        
        for (int num : nums) freq[num]++;
        
        while (!freq.empty()) {
            vector<int> subRes;
            vector<int> toErase;
            for (auto& [num, cnt] : freq) {
                subRes.push_back(num);
                cnt--;
                if (cnt == 0) toErase.push_back(num);
            }
            for (int num : toErase) freq.erase(num);
            res.push_back(subRes);
        }
        return res;
    }
};