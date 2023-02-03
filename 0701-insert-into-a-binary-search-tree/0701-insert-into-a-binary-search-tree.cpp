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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
//         if (root == NULL) {
//             return new TreeNode(val);
//         }
        
//         auto curr = root;
        
//         while (true) {
//             if (val > curr->val) {
//                 if (curr->right == NULL) {
//                     curr->right = new TreeNode(val);
//                     return root;
//                 }
//                 curr = curr->right;
//             } else {
//                 if (curr->left == NULL) {
//                     curr->left = new TreeNode(val);
//                     return root;
//                 }
//                 curr=curr->left;
//             }
//         }
        // USING RECURSION
        if (root == NULL) {
            return new TreeNode(val);
        }
        
        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        } else {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};