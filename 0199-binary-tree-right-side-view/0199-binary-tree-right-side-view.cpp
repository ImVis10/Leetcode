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
    vector<int> rightSideView(TreeNode* root) {
        int level = 0;
        vector<int> res;
        dfs(root, level, res);
        return res;
    }
private:
    void dfs(TreeNode* root, int level, vector<int>& res) {
        if (!root) return;
        
        if (level == res.size()) { // to ensure for each level, we only add the first node we encounter 
            res.push_back(root->val);
        }
        
        dfs(root->right, level + 1, res);
        dfs(root->left, level + 1, res);
    }
    
    
};