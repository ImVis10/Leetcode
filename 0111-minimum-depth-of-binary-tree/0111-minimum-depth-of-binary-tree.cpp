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
    int minDepth(TreeNode* root) {
        // DFS
        return dfs(root);
    }
private:
    int dfs(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        
        if (node->left == NULL) {
            return 1 + dfs(node->right);
        } 
        if (node->right == NULL) {
            return 1 + dfs(node->left);
        }
        
        return 1 + min(dfs(node->left), dfs(node->right));
    }
};