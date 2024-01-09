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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1, tree2, res;
        inorder(root1, tree1);
        inorder(root2, tree2);
        int i = 0, j = 0;
        while (i < tree1.size() and j < tree2.size()) {
            if (tree1[i] <= tree2[j]) {
                res.push_back(tree1[i++]);
            } else {
                res.push_back(tree2[j++]);
            }
        }
        while (i < tree1.size()) {
            res.push_back(tree1[i++]);
        }
        while (j < tree2.size()) {
            res.push_back(tree2[j++]);
        }
        return res;
    }
private:
    void inorder(TreeNode* root, vector<int>& tree) {
        if (!root) return;
        inorder(root->left, tree);
        tree.push_back(root->val);
        inorder(root->right, tree);
    }
};