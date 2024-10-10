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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) return {};
        unordered_map<int, map<int, multiset<int>>> mp;
        int minCol = 0, maxCol = 0;
        queue<pair<pair<int,int>, TreeNode*>> q;
        q.push({{0, 0}, root});
        
        while (!q.empty()) {
            auto curr = q.front(); q.pop();
            int row = curr.first.first, col = curr.first.second;
            minCol = min(col, minCol);
            maxCol = max(col, maxCol);
            TreeNode* node = curr.second;
            mp[col][row].insert(node->val);
            if (node->left) q.push({{row + 1, col - 1}, node->left});
            if (node->right) q.push({{row + 1, col + 1}, node->right});
        }
        
        vector<vector<int>> res;
        for (int col = minCol; col <= maxCol; col++) {
            vector<int> colNodes;
            for (auto& row : mp[col]) {
                colNodes.insert(colNodes.end(), row.second.begin(), row.second.end());
            }
            res.push_back(colNodes);
        }
        return res;
    }
};