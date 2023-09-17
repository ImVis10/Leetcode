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
    TreeNode* prev;
public:
    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }
private:
    bool inorder(TreeNode* node) {
        if (node) {
            if (!inorder(node->left)) {
                return false;
            }
            if (prev && node->val <= prev->val) {
                return false;
            }
            prev = node;
            return inorder(node->right);
        }
        return true;
    }
};