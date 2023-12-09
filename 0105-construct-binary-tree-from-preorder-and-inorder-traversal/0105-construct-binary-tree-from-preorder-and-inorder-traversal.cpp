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
        int curr = 0;
        return build(preorder, inorder, curr, 0, inorder.size() - 1);
    }
private:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& curr, int start, int end) {
        if (start > end) return NULL;
        
        int splitPos = 0;
        
        TreeNode* root = new TreeNode(preorder[curr]);
        
        for (int i = 0; i < preorder.size(); i++) {
            if (inorder[i] == preorder[curr]) {
                splitPos = i;
                break;
            }
        }
        
        curr++; // root is set in its position, now move forward to build the rest of the tree
        
        // divide and conquer
        root->left = build(preorder, inorder, curr, start, splitPos - 1);
        root->right = build(preorder, inorder, curr, splitPos + 1, end); 
        return root;
    }
};