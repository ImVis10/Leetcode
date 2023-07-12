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
    int count = 0;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* LCA = getLCA(root, p, q);
        return count == 2 ? LCA : NULL;
    }
private:
    TreeNode* getLCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        // same as LCA - I
        // catch is either of p or q, or both might not exist in the tree
        // in that case return NULL
        
        // How to check for existence of a node?
        // when we encounter a node, increment a count variable
        // if count is 2, we have both the nodes, so return the LCA
        // else if count < 2, return NULL
        
        if (!root) return root;
        // if (root == p || root == q) { // can't place it here as we need to traverse the entire tree, as we have to check for existence of both the nodes
        //     count++;
        //     return root;
        // }
        
        TreeNode* left = getLCA(root->left, p, q);
        TreeNode* right = getLCA(root->right, p, q);
        
        if (root == p || root == q) {
            count++;
            return root;
        }
        
        if (!left) return right;
        else if (!right) return left;
        else return root;
    }
};