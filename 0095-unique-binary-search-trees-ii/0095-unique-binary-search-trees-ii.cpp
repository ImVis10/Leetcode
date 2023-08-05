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
    vector<TreeNode*> generateTrees(int n) {
        return actuallyGenerateTrees(1, n);
    }
private:
    vector<TreeNode*> actuallyGenerateTrees(int left, int right) {
        if (left == right) { // if tree has only 1 node
            return vector<TreeNode*>{new TreeNode(left)};
        }
        
        if (left > right) {
            return vector<TreeNode*>{nullptr};
        }
        
        vector<TreeNode*> res;
        for (int node = left; node <= right; node++) { // rooted at node
            for (auto leftTree : actuallyGenerateTrees(left, node - 1)) {
                for (auto rightTree: actuallyGenerateTrees(node + 1, right)) {
                    TreeNode* root = new TreeNode(node, leftTree, rightTree);
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};