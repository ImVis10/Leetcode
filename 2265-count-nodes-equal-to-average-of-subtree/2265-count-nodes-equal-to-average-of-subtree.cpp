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
    int averageOfSubtree(TreeNode* root) {
        int res = 0;
        
        getChildrenCountAndSum(root, res);
        return res;
    }
private:
    pair<int, int> getChildrenCountAndSum(TreeNode* root, int& res) {
        if (!root) return {0, 0};
        
        auto [leftCount, leftSum] = getChildrenCountAndSum(root->left, res);
        auto [rightCount, rightSum] = getChildrenCountAndSum(root->right, res);
        
        int sum = root->val + leftSum + rightSum;
        int count = leftCount + rightCount + 1;
        if (sum / count == root->val) res++;
        
        return {count, sum};
    }
}; 