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
        vector<vector<int>> res;
        
        if (root == NULL) return res;
        
        // even levels (starting from 0) are printed normally
        // odd levels must be reversed
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int n = q.size();
            vector<int> level;
            
            for (int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop();
                
                level.push_back(node->val);
                
                if (node->left != NULL) {
                    q.push(node->left);
                }
            
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }

            if (res.size() % 2 != 0) { // indicating odd level based on the size of the res
                reverse(level.begin(), level.end());
            }
            res.push_back(level);
        }
        return res;
    }
};