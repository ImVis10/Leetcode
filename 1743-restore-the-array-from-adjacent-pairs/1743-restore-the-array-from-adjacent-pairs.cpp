class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size() + 1;
        
        unordered_map<int, vector<int>> graph;
        unordered_map<int, bool> visited;
        
        for (auto& pair : adjacentPairs) {
            graph[pair[0]].push_back(pair[1]); visited[pair[0]] = false; 
            graph[pair[1]].push_back(pair[0]); visited[pair[1]] = false;
            
        }
        
        vector<int> res;
        
        for (auto& [k, v] : graph) {
            if (v.size() == 1 && !visited[k]) {
                dfs(k, graph, visited, n, res);
            }
        }
        return res;
    }
private:
    void dfs(int num, unordered_map<int, vector<int>>& graph, unordered_map<int, bool>& visited, int n, vector<int>& res) {
        if (res.size() == n || visited[num]) return;
        
        visited[num] = true;
        
        res.push_back(num);
        
        for (int p : graph[num]) {
            if (!visited[p]) dfs(p, graph, visited, n, res);
        }
    }
};