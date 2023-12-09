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
    int dfs(TreeNode* root, int currPathMax) {
        if (!root) return 0;
        
//         int goodNodes = 0;
        
//         if (root->val >= currPathMax) {
            
//         }
        if (root->val < currPathMax) {
            return dfs(root->left, currPathMax) + dfs(root->right, currPathMax);
        } else {
            currPathMax = root->val;
            return 1 + dfs(root->left, currPathMax) + dfs(root->right, currPathMax);
        }
        return 0;
        
    }
};