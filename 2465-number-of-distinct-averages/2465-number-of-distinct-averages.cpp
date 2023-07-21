class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        // int n = nums.size();
        // int i = 0,  j = n - 1;
        sort(nums.begin(), nums.end());
        set<int> set;
        while (nums.size() > 0) {
            int front = nums.front();
            nums.erase(nums.begin());
            
            int back = nums.back();
            nums.pop_back();
            
            set.insert(front + back);
        }
        return set.size();
    }
};