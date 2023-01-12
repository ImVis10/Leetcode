class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        
        int n = nums.size();
        
        set<int> set;
        
        for(int num : nums) {
            set.insert(num);
        }
        
        for (int i = 1; i <= n; i++) {
            if(!set.count(i)) {
                res.push_back(i);
            }
        }
        return res;
    }
};