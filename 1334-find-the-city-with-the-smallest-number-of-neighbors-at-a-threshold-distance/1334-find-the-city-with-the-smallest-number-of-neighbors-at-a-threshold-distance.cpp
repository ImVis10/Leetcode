class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // all pair shortest path - floyd warshall
        const int INF = 1e9 + 7;
        
        int res, reachMinCities = n;
        
        vector<vector<int>> dist(n, vector<int>(n, INF));
        
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        
        for (auto& edge : edges) { // bidirec
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];   
        }
        
        // apply floyd warshall's shortest path now
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
        // find the city with the smallest no. of reachable cities 
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    if (dist[i][j] <= distanceThreshold) {
                        cnt++;
                    }
                }
            }
            if (cnt <= reachMinCities) {
                reachMinCities = cnt;
                res = i;
            }
        }
        return res;
    }
};