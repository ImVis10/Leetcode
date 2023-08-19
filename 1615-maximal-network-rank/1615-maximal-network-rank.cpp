class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        // number of edges from each of pair of cities
        // return the max among them
        
        vector<unordered_set<int>> adj(n);
        
        for (auto& road : roads) {
            adj[road[0]].insert(road[1]);
            adj[road[1]].insert(road[0]);
            
        }
        
        int res = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rank = adj[i].size() + adj[j].size();
                if (adj[j].find(i) != adj[j].end()) rank -= 1;
                res = max(rank, res);
            }
        }
        return res;
    }
};