class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // all pair shortest path - use floyd warshall
        const int INF = 1e9 + 7, n = original.size(), nodes = 26;
        long long res = 0;
        vector<vector<long long>> dist(26, vector<long long>(26, INF));
        
        for (int i = 0; i < n; i++) {
            int start = original[i] - 'a';
            int end = changed[i] - 'a';
            dist[start][end] = min((long long)cost[i], dist[start][end]);
        }
            
        for (int k = 0; k < nodes; k++) {
            for (int i = 0; i < nodes; i++) {
                for (int j = 0; j < nodes; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
        for (int i = 0; i < source.size(); i++) {
            if (source[i] != target[i]) {
                int start = source[i] - 'a';
                int end = target[i] - 'a';
                if (dist[start][end] == INF) {
                    return -1;
                }
                res += dist[start][end];
            }
        }
        return res;
    }
};