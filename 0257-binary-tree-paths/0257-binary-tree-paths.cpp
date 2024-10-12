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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        string path;
        vector<string> res;
        dfs(root, path, res);
        return res;
    }
private:
    void dfs(TreeNode* root, string path, vector<string>& res) {
        if (!root) return;
        path += to_string(root->val) + "->";
        if (!root->left and !root->right) {
            path.pop_back();
            path.pop_back();
            res.push_back(path);
        }
        // path += to_string(root->val) + "->";
        dfs(root->left, path, res);
        dfs(root->right, path, res);
    }
};