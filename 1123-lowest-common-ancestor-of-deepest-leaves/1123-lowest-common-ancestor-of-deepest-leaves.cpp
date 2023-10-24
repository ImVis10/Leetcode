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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int maxDepth = 0;
        TreeNode* res;
        dfs(root, 0, maxDepth, res);
        return res;
    }
private:
    int dfs(TreeNode* root, int depth, int& maxDepth, TreeNode* &res) {
        if (!root) return depth;

        int lh = dfs(root->left, depth + 1, maxDepth, res);
        int rh = dfs(root->right, depth + 1, maxDepth, res);

        int depthOfSubTree = max(lh, rh);
        maxDepth = max(maxDepth, depthOfSubTree);

        if (lh == rh && lh == maxDepth) res = root; // key statement of the logic
        return depthOfSubTree;
    }
};