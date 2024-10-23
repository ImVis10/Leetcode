class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        int i = 0 , j = 0, m = a.size(), n = b.size();
        vector<vector<int>> res;
        
        while (i < m and j < n) {
            // if (i < m and j < n) {
                if ((a[i][0] <= b[j][0] and b[j][0] <= a[i][1]) or (b[j][0] <= a[i][0] and a[i][0] <= b[j][1])) {
                               res.push_back({max(a[i][0], b[j][0]), min(a[i][1], b[j][1])});
                }
                if (a[i][1] < b[j][1]) i++;
                else j++; 
            // }
        }
        return res;
    }
};