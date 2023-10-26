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
    int maxAncestorDiff(TreeNode* root) {
       return dfs(root, root->val, root->val); 
    }
private:
    int dfs(TreeNode* root, int minVal, int maxVal) {
        if (!root) return maxVal - minVal;
        minVal = min(root->val, minVal);
        maxVal = max(root->val, maxVal);
        return max(dfs(root->left, minVal, maxVal), dfs(root->right, minVal, maxVal));
    }
};