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
    vector<int> inorderList;
    
    int minDiffInBST(TreeNode* root) {
        inorderList = inorderTraversal(root);
        
        int minDiff = INT_MAX;
        
        for (int i = 0; i < inorderList.size() - 1; i++) {
            minDiff = min(minDiff, abs(inorderList[i] - inorderList[i + 1]));
        }
        
        return minDiff;
        
    }
    

    
private:
    void dfs(TreeNode* root) {
        if (root == NULL) return;
        
        dfs(root->left);
        inorderList.push_back(root->val);
        dfs(root->right);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return inorderList;
    }
};