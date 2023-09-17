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
    int maxPathSum(TreeNode* root) {
        int maxPathSum = INT_MIN;
        dfs(root, maxPathSum);
        return maxPathSum;
    }
private:
    int dfs(TreeNode* node, int& maxPathSum) {
        if (!node) return 0;
        
        int left = max(dfs(node->left, maxPathSum), 0); // 0 coz the node->left can be -ve and no need to add to the path as it reduces the sum
        int right = max(dfs(node->right, maxPathSum), 0); // 0 coz the node->left can be -ve and no need to add to the path as it reduces the sum
        
        int currPathSum = node->val + left + right;
        maxPathSum = max(maxPathSum, currPathSum);
        
        return node->val + max(left, right); // without splitting
    }
};