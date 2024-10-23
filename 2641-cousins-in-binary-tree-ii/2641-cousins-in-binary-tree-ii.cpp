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
        
        int totalSumOfCurrLevel = root->val;
        
        while (!q.empty()) {
            int levelSize = q.size();
            int currSumOfNextLevel = 0;
            while (levelSize--) {
                auto curr = q.front(); q.pop();
                curr->val = totalSumOfCurrLevel - curr->val;
                
                int siblingSum = (curr->left ? curr->left->val : 0) + (curr->right ? curr->right->val : 0);
                
                if (curr->left) {
                    currSumOfNextLevel += curr->left->val;
                    curr->left->val = siblingSum;
                    q.push(curr->left);
                }
                
                if (curr->right) {
                    currSumOfNextLevel += curr->right->val;
                    curr->right->val = siblingSum;
                    q.push(curr->right);
                }
            }
            totalSumOfCurrLevel = currSumOfNextLevel;
        }
        return root;
    }
};