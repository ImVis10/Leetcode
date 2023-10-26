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
    int xDepth, yDepth, xParent, yParent;
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (root->val == x || root->val == y) return false;
        dfs(root, x, y, 0, -1);
        
        if (xDepth == yDepth && xParent != yParent) return true;
        return false;
    }
private:
    void dfs(TreeNode* root, int x, int y, int depth, int parent) {
        if (!root) return;
        
        if (root->val == x) {
            xDepth = depth;
            xParent = parent;
        }
        
        if (root->val == y) {
            yDepth = depth;
            yParent = parent;
        }
        
        dfs(root->left, x, y, depth + 1, root->val);
        dfs(root->right,x,y, depth + 1, root->val);
    }
};