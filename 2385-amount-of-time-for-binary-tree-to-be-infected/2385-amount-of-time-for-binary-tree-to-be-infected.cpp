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
        auto p = getHeightAndStartNode(root, parent, start);
        
        int height = p.first;
        TreeNode* startNode = p.second;
        
        unordered_map<TreeNode*, bool> visited;
        visited[startNode] = true;
        
        queue<TreeNode*> q;
        q.push(startNode);
        
        int time = -1;
        
        while (!q.empty()) {
            time++;
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                TreeNode* currNode = q.front();
                q.pop();
                if (parent[currNode] and !visited[parent[currNode]]) {
                    q.push(parent[currNode]);
                    visited[parent[currNode]] = true;
                }
                if (currNode->left and !visited[currNode->left]) {
                    q.push(currNode->left);
                    visited[currNode->left] = true;
                }
                if (currNode->right and !visited[currNode->right]) {
                    q.push(currNode->right);
                    visited[currNode->right] = true;
                }
            }
        }
        return time;
    }
private:
    pair<int, TreeNode*> getHeightAndStartNode(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent, int start) {
        if (!root) return {0, NULL};
        
        queue<TreeNode*> q;
        q.push(root);
        
        int height = 0;
        
        TreeNode* startNode;
        
        while (!q.empty()) {
            height++;
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                TreeNode* currNode = q.front();
                q.pop();
                if (currNode->val == start) startNode = currNode;
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
        return {height, startNode};
    }
};