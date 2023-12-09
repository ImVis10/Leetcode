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
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
private:
    int dfs(TreeNode* root, int currPathMax) { // node should not be less than current path maximum to be considered as a good node
        if (!root) return 0;
        
        if (root->val < currPathMax) { // bad node
            return dfs(root->left, currPathMax) + dfs(root->right, currPathMax);
        } else { // good node
            currPathMax = root->val;
            return 1 + dfs(root->left, currPathMax) + dfs(root->right, currPathMax);
        }
        return 0;
        
    }
};