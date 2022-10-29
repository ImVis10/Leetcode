/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {

    TreeNode prev;
    public boolean isValidBST(TreeNode root) {
        // do an inorder traversal, if the result is in sorted order it means that the tree is BST. 
        return inorder(root);
    }

    private boolean inorder(TreeNode root) {
        if (root != null) {
            if (!inorder(root.left)) {
                return false;
            }
            if (prev != null && root.val <= prev.val) { // No need of using extra space as we can get out of inorder traversal if the current value is less than the previous node.
                return false;
            }
            prev = root;

            return inorder(root.right);
        }
        return true;
    }
}