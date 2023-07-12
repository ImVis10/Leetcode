class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // Nodes part of a cycle are not "eventually" safe
        // Removing '0' out-degree nodes would be the work to do.
        // remove them add them to the result set
        // do the above repeatedly, until there are no '0' out-degree nodes
        
        int numNodes = graph.size();
        
        // we need a map or something that holds the info regarding the inward edges to a node
        vector<vector<int>> inward(numNodes);
        vector<int> outDegree(numNodes);
        queue<int> q;
        
        for (int nodeFrom = 0; nodeFrom < numNodes; nodeFrom++) {
            for (auto nodesTo : graph[nodeFrom]) {
                inward[nodesTo].push_back(nodeFrom);
            }
            outDegree[nodeFrom] = graph[nodeFrom].size();
            if (outDegree[nodeFrom] == 0) q.push(nodeFrom);
        }
        
        vector<bool> safe(numNodes);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe[node] = true;
            for (auto from : inward[node]) {
                if (--outDegree[from] == 0) q.push(from);
            }
        }
        
        vector<int> res;
        for (int node = 0; node < numNodes; node++) {
            if (safe[node]) res.push_back(node);
        }
        return res;
    }
};