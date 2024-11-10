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
        // same as leetcode 314, but the difference is for any two nodes in same row and col, they must be sorted in ascending order
        // so we need two things different from leetcode 314 where we only consider column
        // here we should consider both row and column
        // and also for the map, the key should be column (same as in 314) but the value must be a map of <row, set> as we need values in sorted order
        // that too a multiset as there might be duplicate numbers for nodes
        
        if (!root) return {};
        unordered_map<int, map<int, multiset<int>>> mp;
        queue<pair<pair<int, int>, TreeNode*>> q;
        int minCol = INT_MAX, maxCol = INT_MIN;
        
        q.push({{0, 0}, root});
        
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            int row = p.first.first, col = p.first.second;
            TreeNode* node = p.second;
            mp[col][row].insert(node->val);
            minCol = min(minCol, col);
            maxCol = max(maxCol, col);
            if (node->left) q.push({{row + 1, col - 1}, node->left});
            if (node->right) q.push({{row + 1, col + 1}, node->right});
        }
        
        vector<vector<int>> res;
        for (int col = minCol; col <= maxCol; col++) {
            vector<int> colNodes;
            for (auto& [row, nodes] : mp[col]) {
                colNodes.insert(colNodes.end(), nodes.begin(), nodes.end());
            }
            res.push_back(colNodes);
        }
        return res;
    }
};