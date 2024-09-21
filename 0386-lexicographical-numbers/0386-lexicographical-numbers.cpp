class Solution {
public:
    vector<int> lexicalOrder(int n) {
        // dfs
        vector<int> res;
        for (int i = 1; i < 10; i++) {
            dfs(i, n, res);
        }
        return res;
    }
    
    void dfs(int curr, int n, vector<int>& res) {
        if (curr > n) return;
        res.push_back(curr);
        curr *= 10;
        for (int i = 0; i < 10; i++) {
            dfs(curr + i, n, res);
        }
    }
};