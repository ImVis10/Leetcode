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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> set;
        return dfs(root, k, set);
    }
private:
    bool dfs(TreeNode* root, int k, unordered_set<int>& set) {
        if (!root) return false;
        if (set.find(k - root->val) != set.end()) return true;
        set.insert(root->val);
        return dfs(root->left, k, set) || dfs(root->right, k, set);
    }
};