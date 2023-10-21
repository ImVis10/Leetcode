class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parent(n, 0);
        vector<bool> visited(n);
        
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) parent[leftChild[i]]++;
            if (rightChild[i] != -1) parent[rightChild[i]]++;
        }
        
        int numRoots = 0, root = -1;
        for (int i = 0; i < n; i++) {
            if (parent[i] > 1) return false;
            else if (parent[i] == 0) {
                numRoots++;
                root = i;
            }
        }
        
        bool hasCycle = dfs(root, leftChild, rightChild, visited);
        
        for (bool vis : visited) {
            if (vis) n--;
        }
        return numRoots == 1 && !hasCycle && n == 0;
    }
private:
    bool dfs(int node, vector<int>& leftChild, vector<int>& rightChild, vector<bool>& visited) { // checks for existence of cycle
        if (node == -1) return false;
        if (visited[node]) return true;
        
        visited[node] = true;
        
        return dfs(leftChild[node], leftChild, rightChild, visited) || dfs(rightChild[node], leftChild, rightChild, visited);
    }
};