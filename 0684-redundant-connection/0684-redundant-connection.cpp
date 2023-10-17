class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        vector<vector<int>> graph(n + 1);
        
        for (auto& edge : edges) { // TC: O(n^2), as we do DFS from every node
            int u = edge[0];
            int v = edge[1];
            vector<bool> visited(n + 1);
            // Check if there is a path from u to v with considering the edge(u, v)
            if (dfs(u, v, graph, visited)) { // Cycle exists and edge(u, v) is causing the cycle
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