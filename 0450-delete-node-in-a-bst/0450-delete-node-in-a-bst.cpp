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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) { // base case
            return root;
        }
        
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == NULL) { // if left subtree of key is NULL
                return root->right;
            } else if (root->right == NULL) { // if right subtree of key is NULL
                return root->left;
            }
            
            // the deleted node can be replaced with the minimum of the right subtree or the maximum of the left subtree
            auto curr = root->left;
            while (curr->right) {
                curr = curr->right;
            }
            root->val = curr->val;
            root->left = deleteNode(root->left, root->val);
        }
        return root;
    }
};