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
    vector<int> res;
    
    int minDiffInBST(TreeNode* root) {
        res = inorderTraversal(root);
        
        int minDiff = INT_MAX;
        
        for (int i = 0; i < res.size() - 1; i++) {
            for (int j = i + 1; j < res.size(); j++) {
                if (abs(res[i] - res[j]) < minDiff) {
                    minDiff = abs(res[i] - res[j]);
                }
            }
        }
        
        return minDiff;
        
    }
    

    
private:
    void dfs(TreeNode* root) {
        if (root == NULL) return;
        
        dfs(root->left);
        res.push_back(root->val);
        dfs(root->right);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return res;
    }
};