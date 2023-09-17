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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> tree;
        inorder(root, tree, k);
        
        return tree[k - 1];
    }
private:
    void inorder(TreeNode* node, vector<int>& res, int k) {
        if (!node || res.size() == k) return;
        inorder(node->left, res, k);
        res.push_back(node->val);
        inorder(node->right, res, k);        
    }
};