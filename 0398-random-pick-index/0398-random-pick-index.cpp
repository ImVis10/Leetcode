class Solution {
public:
    unordered_map<int, vector<int>> mp; // val -> idx
    Solution(vector<int>& nums) {
        for (int i = 0;i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        vector<int> indices = mp[target];
        int randIdx = rand() % indices.size();
        return indices[randIdx];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */