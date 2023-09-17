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
    int dfs(TreeNode* node, int currPathMax) {
        if (!node) return 0;
        
        int cnt = 0;
        if (node->val >= currPathMax) {
            currPathMax = node->val;
            cnt = 1;
        }
        
        cnt += dfs(node->left, currPathMax);
        cnt += dfs(node->right, currPathMax);
        
        return cnt;
    }
};