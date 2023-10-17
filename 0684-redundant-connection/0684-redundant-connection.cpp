class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        vector<vector<int>> graph(n + 1);
        
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            vector<bool> visited(n + 1);
            if (dfs(u, v, graph, visited)) { // Cycle exists and edge is causing the cycle
                return edge;
            }
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return {};
    }
private:
    bool dfs(int u, int v, vector<vector<int>>& graph, vector<bool>& visited) {
        if (u == v) return true;
        visited[u] = true;
        
        for (int neigh : graph[u]) {
            if (!visited[neigh] && dfs(neigh, v, graph, visited)) {
                return true;
            }
        }
        return false;
    }
};