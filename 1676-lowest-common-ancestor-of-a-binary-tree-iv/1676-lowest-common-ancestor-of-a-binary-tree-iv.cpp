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
    int count = 0;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        set<TreeNode*> set(nodes.begin(), nodes.end()); // just so that it'll be useful when we encounter this node
        return getLCA(root, set);
    }
private:
    TreeNode* getLCA(TreeNode* root, set<TreeNode*> set) {
        if(!root) return root;
        if(set.count(root)) return root;
        
        TreeNode* left = getLCA(root->left, set);
        TreeNode* right = getLCA(root->right, set);
        
        if(!left) return right;
        else if (!right) return left;
        else return root;
    }
};