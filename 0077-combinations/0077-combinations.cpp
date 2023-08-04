class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums(n);
        vector<vector<int>> res;
        vector<int> comb;
        recurse(1, n, k, comb, res);
        return res;
    }
    
private:
    void recurse(int start, int end, int k, vector<int> comb, vector<vector<int>>& res) {
        if (comb.size() == k) {
            res.push_back(comb);
            return;
        }
        
        for (int i = start; i <= end; i++) {
            comb.push_back(i);
            recurse(i + 1, end, k, comb, res);
            comb.pop_back(); // backtrack, so that the next element can sit here
        }
    }
};