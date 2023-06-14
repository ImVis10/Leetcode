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
    vector<int> nodes;
public:
    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX;
        inorderTraversal(root);
        
        int n = nodes.size();
        for (int i = 1; i < n; i++) {
            int diff = abs(nodes[i] - nodes[i - 1]);
            if (diff < res) {
                res = diff;
            }
        }
        return res;
    }
    
private:
    void inorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        inorderTraversal(root->left);
        nodes.push_back(root->val);
        inorderTraversal(root->right);
    }
    
};