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
    int count = 0;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        if (!root) return root;
        for (auto& node : nodes) {
            if (node == root) return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, nodes);
        TreeNode* right = lowestCommonAncestor(root->right, nodes);
        
        if(!left) return right;
        else if (!right) return left;
        else return root;
    }
};