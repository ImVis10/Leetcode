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
    int diameterOfBinaryTree(TreeNode* root) { // diameter at a node would be the sum of its left subtree's height and right subtree's height
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
private:
    int height(TreeNode* root, int& diameter) {
        if (!root) return 0;
        int lh = height(root->left, diameter);
        int rh = height(root->right, diameter);
        diameter = max(diameter, lh + rh);
        return 1 + max(lh, rh);
    }
};