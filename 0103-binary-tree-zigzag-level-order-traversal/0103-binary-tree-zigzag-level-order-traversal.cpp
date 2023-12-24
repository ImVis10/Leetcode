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
        
        queue<TreeNode*> q;
        q.push(root);
        
        vector<vector<int>> res;
        
        bool evenLevel = true;
        
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> level(levelSize);
            for (int i = 0; i < levelSize; i++) {
                auto currNode = q.front();
                q.pop();
                int idx = evenLevel ? i : levelSize - i - 1;
                level[idx]= currNode->val;
                if (currNode->left) {
                    q.push(currNode->left);
                }
                if (currNode->right) {
                    q.push(currNode->right);
                }
            }
            evenLevel = !evenLevel;
            res.push_back(level);
        }
        return res;
    }
};