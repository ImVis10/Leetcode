/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root or !p or ! q or p == root or q == root or (root->val > p->val and root->val < q->val) or (root->val < p->val and root->val > q->val))  {
            return root;
        }
        
        if (root->val > p->val and root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (root->val < p->val and root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return NULL;
    }
};