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
    void flatten(TreeNode* root) {
        if (!root) return;
        TreeNode* prev = nullptr;
        preorder(root, prev);
    }
private:
    void preorder(TreeNode* root, TreeNode* &prev) {
        if (!root) return;
        TreeNode* rightSubTree = root->right;
        if (prev) {
            prev->right = root;
            prev->left = nullptr;
        }
        prev = root;
        preorder(root->left, prev);
        preorder(rightSubTree, prev);
    }
};