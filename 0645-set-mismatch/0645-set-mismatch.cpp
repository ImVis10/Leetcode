class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2;
        
        set<int> set;
        for (int num : nums) {
            set.insert(num);
        }
        
        int actualSum = accumulate(nums.begin(), nums.end(), 0);
        int setSum = accumulate(set.begin(), set.end(), 0);
        
        int duplicate = actualSum - setSum;
        int missing = expectedSum - setSum;
        
        return {duplicate, missing};
        
    }
};