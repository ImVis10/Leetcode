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
    bool isBalanced(TreeNode* root) {
        // Height balanced = abs(height(leftSubTree) - height(rightSubTree)) <= 1, for every node in the tree this must be true
        // we can actually do a dfs for every node in the tree and ask each node if it is balanced
        // a dfs takes O(n) --> n = number of nodes in the tree
        // So doing dfs on each node takes O(n ^ 2)
        // So let's do dfs from the bottom(instead from root) because by following this approach we'll visit each                   node only once
        // we keep asking each node from the bottom whether it has a balanced subtree
        
        int height = 0;
        return dfs(root, height);
    }

private:
    bool dfs(TreeNode* root, int& height) { // checks whether the tree rooted at any node in the tree is balanced
        // Height is also calculated at each node of the tree because a tree rooted at a node is not quite height balanced when both the left and right subtrees are height balanced, it is only height balanced when the difference between the heights of left and right subtrees is no greater than 1
        
        // eg: Suppose a tree is rooted at a node 'p'. Height of left subtree is 4 and it is height-balanced. Height of right subtree is 7 and it is also height balanced. So eventhough both the subtrees of 'p' are height-balanced. it doesn't mean that subtree rooted at 'p' is balanced as the difference between the subtrees of p is > 1 (7 - 4 = 3 > 1)
        if (root == NULL) {
            // height = -1;
            return true;
        }
        
        int heightOfLeftSubTree = 0, heightOfRightSubTree = 0;
        
        if (!dfs(root->left, heightOfLeftSubTree) || !dfs(root->right, heightOfRightSubTree)) { // even if one node in the  tree is not height balanced, return false
            return false;
        }
        
        if (abs(heightOfLeftSubTree - heightOfRightSubTree) > 1) {
            return false;
        }
        
        height = 1 + max(heightOfLeftSubTree, heightOfRightSubTree);
        return true;
    }
};