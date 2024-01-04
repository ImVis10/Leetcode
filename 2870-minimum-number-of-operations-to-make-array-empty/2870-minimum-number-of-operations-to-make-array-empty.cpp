class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), res = 0;
        
        unordered_map<int, int> freq;
        
        for (int num : nums) freq[num]++;
        
        for (auto& [num, cnt] : freq) {
            if (cnt == 1) return -1;
            res += (cnt / 3) + (cnt % 3 != 0);
        }
        return res;
    }
};