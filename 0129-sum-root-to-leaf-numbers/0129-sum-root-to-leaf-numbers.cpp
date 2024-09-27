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
    int sumNumbers(TreeNode* root) {
        int res = 0;
        dfs(root, 0, res);
        return res;
    }
private:
    void dfs(TreeNode* root, int curr, int& res) {
        if (!root) return;
        curr = root->val + (curr * 10);
        if (!root->left and !root->right) res += curr;
        dfs(root->left, curr, res);
        dfs(root->right, curr, res);
    }
};