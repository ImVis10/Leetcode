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
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        return build(preorder, inorder, 0, inorder.size() - 1, idx);
    }
private:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int start, int end, int& idx) {
        if (start > end) return NULL;
        
        TreeNode* root = new TreeNode(preorder[idx]);
        
        int splitAt = 0;
        
        for (int i = 0; i < inorder.size(); i++) {
            if (preorder[idx] == inorder[i]) {
                splitAt = i;
                break;
            }
        }
        idx++;
        
        root->left = build(preorder, inorder, start, splitAt - 1, idx);
        root->right = build(preorder, inorder, splitAt + 1, end, idx);
        return root;
    }
};