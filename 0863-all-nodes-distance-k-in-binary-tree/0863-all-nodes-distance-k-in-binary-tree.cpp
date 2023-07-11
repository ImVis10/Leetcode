/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        getParentMap(root, parent);
        
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int currDistance = 0;
        
        // CONVERTED TREE TO AN UNDIRECTED GRAPH, SO NOW WE HAVE PARENT POINTERS AS WELL
        while (!q.empty()) {
            int qSize = q.size();
            if (currDistance++ == k) break;
            for (int i = 0; i < qSize; i++) {
                TreeNode* currNode = q.front();
                q.pop(); 
                if (parent[currNode] && !visited[parent[currNode]]) { // for parent
                    q.push(parent[currNode]);
                    visited[parent[currNode]] = true;
                }
                if (currNode->left && !visited[currNode->left]) { // left child
                    q.push(currNode->left);
                    visited[currNode->left] = true;
                }
                if (currNode->right && !visited[currNode->right]) { // right child
                    q.push(currNode->right);
                    visited[currNode->right] = true;
                }
            }
        }
        
        vector<int> res;
        while (!q.empty()) {
            TreeNode* resNode = q.front();
            q.pop();
            res.push_back(resNode->val);
        }
        return res;
    }
    
private:
    void getParentMap(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* currNode = q.front();
            q.pop();
            if (currNode->left) {
                q.push(currNode->left);
                parentMap[currNode->left] = currNode;
            }
            if (currNode->right) {
                q.push(currNode->right);
                parentMap[currNode->right] = currNode;
            }
        }
    }
};