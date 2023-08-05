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
        // unordered_map<pair<int, int>, vector<TreeNode*>> cache;
        return actuallyGenerateTrees(1, n);
    }
private:
    vector<TreeNode*> actuallyGenerateTrees(int left, int right) {
        // if (left == right) { // if tree has only 1 node
        //     return vector<TreeNode*>{new TreeNode(left)};
        // } 
        // NOT NEEDED AS IT IS ALREADY BEING COMPUTED BY THE FOR LOOPS BELOW
        
        if (left > right) {
            return vector<TreeNode*>{nullptr};
        }
        
        // if (map.find({left, right}) != map.end()) {
        //     return cache[{left, right}];
        // }
        
        vector<TreeNode*> res;
        for (int node = left; node <= right; node++) { // rooted at node
            for (auto leftTree : actuallyGenerateTrees(left, node - 1)) {
                for (auto rightTree: actuallyGenerateTrees(node + 1, right)) {
                    TreeNode* root = new TreeNode(node, leftTree, rightTree);
                    res.push_back(root);
                }
            }
        }
        // cache[{left, right}] = res;
        return res;
    }
};