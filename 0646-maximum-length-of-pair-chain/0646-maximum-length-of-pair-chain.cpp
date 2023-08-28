class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int res = 1; // minimum length of the chain
        
        int end = pairs[0][1];
        
        for (int i = 1; i < pairs.size(); i++) {
            if (end < pairs[i][0]) {
                res++;
                end = pairs[i][1];
            }
        }
        return res;
    }
};