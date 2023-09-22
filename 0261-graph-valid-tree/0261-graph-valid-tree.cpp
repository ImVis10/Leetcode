class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // detect if there is a cycle in the given graph if it is connected
        // disconnected graph - not a tree
        // connected graph with a cycle - not a tree
        // connected graph without a cycle - tree
        unordered_map<int, unordered_set<int>> graph;
        
        for (auto& edge : edges) { // building adjancency list
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        
        unordered_set<int> visited;
        
        if (!dfs(0, -1, graph, visited)) return false;
        
        return visited.size() == n; // valid tree only when the graph is connected. For a disconnected graph all the nodes in the graph won't be visited.
    }
    
private:
    bool dfs(int node, int parent, unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& visited) {
        if (visited.count(node)) return false;
        
        visited.insert(node);
        
        for (int neighbor : graph[node]) {
            if (neighbor != parent && !dfs(neighbor, node, graph, visited)) return false;
        }
        return true;
    }
};