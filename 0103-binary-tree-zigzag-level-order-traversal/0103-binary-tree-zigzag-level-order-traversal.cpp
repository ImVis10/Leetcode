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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> levelOrder = levelOrderTraversal(root);
        int levels = levelOrder.size();
        for (int i = 0; i < levels; i++) {
            if (i % 2) reverse(levelOrder[i].begin(), levelOrder[i].end());
        }
        return levelOrder;
    }
private:
    vector<vector<int>> levelOrderTraversal(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        vector<vector<int>> res;
        
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> level;
            for (int i = 0; i < levelSize; i++) {
                auto currNode = q.front();
                q.pop();
                level.push_back(currNode->val);
                if (currNode->left) {
                    q.push(currNode->left);
                }
                if (currNode->right) {
                    q.push(currNode->right);
                }
            }
            res.push_back(level);
        }
        return res;
    }
};