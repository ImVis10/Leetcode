/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        pair<int, TreeNode*> p = getNumberOfLevels(root, parent, start);
        int height = p.first;
        
        TreeNode* startNode = p.second;
        queue<TreeNode*> q;
        q.push(startNode);
        
        unordered_map<TreeNode*, bool> visited;
        visited[startNode] = true;
        int time = -1;
        
        while (!q.empty()) {
            int qSize = q.size();
            time++;
            for (int i = 0; i < qSize; i++) {
                TreeNode* currNode = q.front();
                // cout << currNode->val << endl;
                q.pop();
                if (parent[currNode] && !visited[parent[currNode]]) {
                    q.push(parent[currNode]);
                    visited[parent[currNode]] = true;
                }
                if (currNode->left && !visited[currNode->left]) {
                    q.push(currNode->left);
                    visited[currNode->left] = true;
                }
                if (currNode->right && !visited[currNode->right]) {
                    q.push(currNode->right);
                    visited[currNode->right] = true;
                }
            }
        }
        return time;
    }
    
private:
    pair<int, TreeNode*> getNumberOfLevels(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent, int start) {
        if (root == NULL) {
            return {0, NULL};
        }
        queue<TreeNode*> q;
        q.push(root);
        int numLevels = 0;
        
        TreeNode* startNode = NULL;
        while (!q.empty()) {
            numLevels++;
            int nodesInLevel = q.size();
            while (nodesInLevel--) {
                TreeNode* currNode = q.front();
                if (currNode->val == start) {
                    startNode = currNode;
                }
                q.pop();
                if (currNode->left) {
                    q.push(currNode->left);
                    parent[currNode->left] = currNode;
                }
                if (currNode->right) {
                    q.push(currNode->right);
                    parent[currNode->right] = currNode;
                } 
            }
        }
        return {numLevels, startNode};
    }
};