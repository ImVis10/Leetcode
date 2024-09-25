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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        int level = 0;
        
        while (!q.empty()) {
            int levelSize = q.size();
            int prevVal = level % 2 == 0 ? -1 : INT_MAX;
            while (levelSize--) {
                TreeNode* node = q.front();
                q.pop();
                if ((level % 2 == 0 and (node->val % 2 == 0 or node->val <= prevVal)) or (level % 2 == 1 and (node->val % 2 == 1 or node->val >= prevVal))) {
                    return 0;
                }
                prevVal = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            level++;
        }
        return 1;
    }
};