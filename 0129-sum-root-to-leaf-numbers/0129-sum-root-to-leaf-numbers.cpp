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
    int res = 0;
public:
    int sumNumbers(TreeNode* root) {
        preOrder(root, 0);
        return res;
    }

private:
    void preOrder(TreeNode* root, int currNum) {
        if (root != NULL) {
            currNum = root->val + currNum * 10;
            
            if (root->left == NULL && root->right == NULL) res += currNum;
            
            preOrder(root->left, currNum);
            preOrder(root->right, currNum);
        }
        
    }
};