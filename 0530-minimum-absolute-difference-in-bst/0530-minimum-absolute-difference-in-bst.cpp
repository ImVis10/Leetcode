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
    int res = INT_MAX;
    
    TreeNode* prevNode;
    
    int getMinimumDifference(TreeNode* root) {
        inorderTraversal(root);
        return res;
    }
    
private:
    void inorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        inorderTraversal(root->left);
        if (prevNode != NULL) {
            res = min(res, root->val - prevNode->val);
        }
        prevNode = root;
        inorderTraversal(root->right);
    }
    
};