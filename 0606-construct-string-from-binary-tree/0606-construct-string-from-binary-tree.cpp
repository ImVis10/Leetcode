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
    string tree2str(TreeNode* root) {
        if (!root) return "";
        
        // string s = to_string(root->val);
        
        string s = "";
        
        dfs(root, s);
        
        return s;
    }
private:
    void dfs(TreeNode* root, string& s) {
        if (!root) return;
        
        s += to_string(root->val);
        
        if (root->left || root->right) {
            s += '(';
            dfs(root->left, s);
            s += ')';
        }
        
        if (root->right) {
            s += '(';
            dfs(root->right, s);
            s += ')';
        }
    }
};