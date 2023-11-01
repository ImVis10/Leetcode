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
    vector<int> findMode(TreeNode* root) {
        int cnt = 0, maxCnt = 0;
        TreeNode* prev = nullptr;
        vector<int> res;
        inorder(root, res, prev, cnt, maxCnt);
        return res;
    }
private:
    void inorder(TreeNode* root, vector<int>& res, TreeNode* &prev, int& cnt, int& maxCnt) {
        if (!root) return;
        
        inorder(root->left, res, prev, cnt, maxCnt);
        
        if (prev && root->val == prev->val) cnt++;
        else cnt = 1;
        
        if (cnt == maxCnt) res.push_back(root->val);
        else if (cnt > maxCnt){
            res.clear();
            res.push_back(root->val);
            maxCnt = cnt;
        }
        
        prev = root;
        
        inorder(root->right, res, prev, cnt, maxCnt);
    }
};