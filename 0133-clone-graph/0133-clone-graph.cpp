/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        return bfs(node);
    }
private:
    Node* bfs(Node* node) {
        queue<Node*> q;
        
        q.push(node);
        
        unordered_map<Node*, Node*> graph;
        graph[node] = new Node(node->val, vector<Node*>());
        
        while (!q.empty()) {
            Node* currNode = q.front();
            q.pop();
            
            for (auto neigh : currNode->neighbors) {
                if (!(graph.find(neigh) != graph.end())) { // if the node is not copied(cloned) to the graph
                    graph[neigh] = new Node(neigh->val, vector<Node*>());
                    q.push(neigh);
                    // graph[currNode]->neighbors.push_back(graph[neigh]); // can't be here as if we encounter a node that is a neighbor but it is already cloned, we cannot add it to the graph
                }
                graph[currNode]->neighbors.push_back(graph[neigh]); // connect the neigbors in the clone
            }
        }
        return graph[node];
    }
};