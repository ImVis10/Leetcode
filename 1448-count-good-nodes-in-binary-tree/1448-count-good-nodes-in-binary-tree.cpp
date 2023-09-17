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
    int res = 0;
public:
    int goodNodes(TreeNode* root) {
        if (root == NULL) return 0;
        dfs(root, root->val);
        return res;
    }
    
private:
    void dfs(TreeNode* node, int currPathMax) {
        if (!node) return;
        
        if (node->val >= currPathMax) {
            currPathMax = node->val;
            res++;
        }
        
        dfs(node->left, currPathMax);
        dfs(node->right, currPathMax);
    }
};