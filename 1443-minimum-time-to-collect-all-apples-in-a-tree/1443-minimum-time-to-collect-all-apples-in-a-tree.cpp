class Solution {
    vector<vector<int>> adjList;
    int res = INT_MAX;
    // start at root (vertex 0) and come back to root finally

public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        adjList.resize(n);
        for (auto edge : edges) {
            adjList[edge[0]].emplace_back(edge[1]);
            adjList[edge[1]].emplace_back(edge[0]);
        }
        return dfs(0, -1, hasApple);
    }
    
private:
    int dfs(int node, int parent, vector<bool>& hasApple) {
        int time = 0;
        
        for(auto child : adjList[node]) { // for all the nodes 'node' is connected to
            if (child == parent) continue; // As this is not exactly a tree, in tree we can move in only one direction from parent to children. But this is an undirected graph, so this biderectional between parent and child
            
            int childTime = dfs(child, node, hasApple); // time taken to collect all apples in the subtree rooted at 'child'
            
            if (childTime || hasApple[child]) { // if the subtree rooted at 'child' has apples or the child node has an apple
                time += 2 + childTime; // adding 2 as we must return back to the origin of traversal for that subtree
            }
            
        }
        return time;
    }
};