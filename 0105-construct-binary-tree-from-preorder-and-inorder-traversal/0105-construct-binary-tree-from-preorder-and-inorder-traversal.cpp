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
        // preorder - to find out which node is the root
        // inorder - to find out the left and right subtrees
        int idx = 0;
        return build(preorder, inorder, 0, preorder.size() - 1, idx);
    }
private:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int start, int end, int& idx) {
        // start, end - pass by value as it is specific to left and right values
        // idx - pass by reference as it needs to be updated across all the calls because it keeps track of the position in preorder vector, which is a shared state across all calls
        if (start > end) return NULL;
        
        TreeNode* root = new TreeNode(preorder[idx]);
        int splitAt = 0;
        
        for (int i = 0; i < inorder.size(); i++) {
            if (preorder[idx] == inorder[i]) {
                splitAt = i;
                break;
            }
        }
        idx++; // prepare for the next node of the tree to place it at the appropriate position
        root->left = build(preorder, inorder, start, splitAt - 1, idx);
        root->right = build(preorder, inorder, splitAt + 1, end, idx);
        return root;
    }
};