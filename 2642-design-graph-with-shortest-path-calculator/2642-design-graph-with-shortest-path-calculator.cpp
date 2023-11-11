class Graph {
    vector<vector<pair<int, int>>> graph;
public:
    Graph(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back({edge[2], edge[1]});
        }
    }
    
    void addEdge(vector<int> edge) {
        graph[edge[0]].push_back({edge[2], edge[1]});
    }
    
    int shortestPath(int node1, int node2) {
        int V = graph.size();
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<int> dist(V, INT_MAX);
        dist[node1] = 0;
        
        pq.push({0, node1});
        
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            
            if (u == node2) break;
            
            for (auto& node : graph[u]) {
                int v = node.second;
                int weight = node.first;
                
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[node2] == INT_MAX ? -1 : dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */