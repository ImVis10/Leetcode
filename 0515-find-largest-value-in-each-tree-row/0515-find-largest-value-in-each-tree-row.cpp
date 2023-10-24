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
    vector<int> largestValues(TreeNode* root) {
        return levelOrderTraversal(root);
    }
private:
    vector<int> levelOrderTraversal(TreeNode* root) {
        if (!root) return {};
        
        queue<TreeNode*> q;
        q.push(root);
        int level = -1;
        
        vector<int> res;
        
        while (!q.empty()) {
            int prevLevel = level;
            level++;
            int levelSize = q.size();
            int levelMax = INT_MIN;
            for (int i = 0; i < levelSize; i++) {
                auto currNode = q.front();
                q.pop();
                if (currNode->left) q.push(currNode->left);
                if (currNode->right) q.push(currNode->right);
                levelMax = max(currNode->val, levelMax);
                if (prevLevel != level) res.push_back(levelMax);
                else res.back() = levelMax;
                prevLevel = level;
            }
        }
        return res;
    }
};