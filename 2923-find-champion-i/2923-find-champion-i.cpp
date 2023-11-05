class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<int> teams(n);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    if (grid[i][j] == 1) teams[i]++;
                }
            }
        }
        
        int res = -1;
        int maxPoints = -1;
        
        for (int i = 0; i < n; i++) {
            if (teams[i] > maxPoints) {
                maxPoints = teams[i];
                res = i;
            }
        }
        return res;
    }
};