/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        vector<TreeNode*> path = findPath(root, target);
        collectNodesAtDistance(target, k, res);
        k -= 1;
        // to find nodes at distance k in the other subtree (of the parent or ancestors)
        for (int i = path.size() - 2; i >= 0 and k >= 0; i--) { // i starts from path.size() - 2 coz path.size() - 1 has target, we should start from the parent of target
            TreeNode* node = path[i];
            if (k == 0) res.push_back(node->val);
            else {
                TreeNode* child = path[i + 1];
                TreeNode* otherSubtree = node->left == child ? node->right : node->left;
                collectNodesAtDistance(otherSubtree, k - 1, res);
            }
            k -= 1;
        }
        return res;
    }
private:
    vector<TreeNode*> findPath(TreeNode* root, TreeNode* target) {
        vector<TreeNode*> path;
        getPath(root, target, path);
        return path;
    }

    bool getPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if (!root) return false;
        path.push_back(root);
        if (root == target) return true;
        if (getPath(root->left, target, path) or getPath(root->right, target, path)) return true;
        path.pop_back();
        return false;
    }

    void collectNodesAtDistance(TreeNode* node, int depth, vector<int>& res) {
        if (!node) return;
        if (depth == 0) {
            res.push_back(node->val);
            return;
        }
        collectNodesAtDistance(node->left, depth - 1, res);
        collectNodesAtDistance(node->right, depth - 1, res);
    }
};