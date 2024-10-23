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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        vector<int> levelSum;
        
        while (!q.empty()) {
            int levelSize = q.size();
            int sum = 0;
            while (levelSize--) {
                auto curr = q.front(); q.pop();
                sum += curr->val;
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            levelSum.push_back(sum);
        }
        
        q.push(root);
        root->val = 0;
        
        int level = 1;
        while (!q.empty()) {
            int levelSize = q.size();
            while (levelSize--) {
                auto curr = q.front(); q.pop();
                int siblingSum = (curr->left ? curr->left->val : 0) + (curr->right ? curr->right->val  : 0);
                if (curr->left) {
                    curr->left->val = levelSum[level] - siblingSum;
                    q.push(curr->left);
                }
                if (curr->right) {
                    curr->right->val = levelSum[level] - siblingSum;
                    q.push(curr->right);
                }
            }
            level++;
        }
        return root;
    }
};