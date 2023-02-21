class Solution {
public:
    long long res = 0;
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        // Redraw the tree with node 0 being the root
        // how many people are going to be at a certain node, that are going to travel from that node back to the node 0(capital city). No overlap between subtrees -- Sub problem
        // num cars * distance = amount of fuel
        // essentially a DFS from node 0 (capital city)
        map<int, vector<int>> adjList;
        
        for (auto& road : roads) {
            adjList[road[0]].push_back(road[1]);
            adjList[road[1]].push_back(road[0]);
        }
        dfs(0, -1, adjList, seats);
        return res;
    }
    
private:
    int dfs(int node, int parent, map<int, vector<int>>& adjList, int seats) {
        int passengers = 0;
        for (auto& child : adjList[node]) {
            if (child != parent) {
                int passengersFromChildNode = dfs(child, node, adjList, seats);
                passengers += passengersFromChildNode;
                res += (int)ceil(passengersFromChildNode * 1.0 / seats);
            }
        }
        return passengers + 1; // adding 1 as we should consider the original node as well
    }
};