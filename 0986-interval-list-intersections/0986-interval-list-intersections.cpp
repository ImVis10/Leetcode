class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        int i = 0 , j = 0, m = a.size(), n = b.size();
        vector<vector<int>> res;
        
        while (i < m and j < n) {
                int start = max(a[i][0], b[j][0]), end = min(a[i][1], b[j][1]);
                if (start <= end) res.push_back({start, end});
                if (a[i][1] < b[j][1]) i++;
                else j++; 
        }
        return res;
    }
};