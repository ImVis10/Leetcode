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
    int diameter = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
       // diameter of every node would be would be the sum of its left subtree and right subtree height
        height(root);
        return diameter;
        
    }
private:
    int height(TreeNode* node) {
        if (node == NULL) return 0;
        
        int lh = height(node->left);
        int rh = height(node->right);
        
        diameter = max(diameter, lh + rh); // diameter can not only be through root as the the nodes with the max distance between them can be on the same side of the root. So storing the diameter value as well.
        
        return 1 + max(lh, rh);
    }
};