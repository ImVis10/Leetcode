/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        // lowest common ancestor - first common ancestor when traversing bottom up i.e. from the leaf nodes (if the leaf nodes are the given inputs)
        // a node can be a descendant of itself.
        // both the given nodes can be in the left sub tree or can be in the right sub tree.
        // If one is in the left and one is in the right, it is obvious that root is the lowest and only common ancestor.
        int rootVal = root.val;
        int pVal = p.val;
        int qVal = q.val;

        if (pVal > rootVal && qVal > rootVal) {
            return lowestCommonAncestor(root.right, p, q);
        } else if (pVal < rootVal && qVal < rootVal) {
            return lowestCommonAncestor(root.left, p, q);
        } else {
            return root;
        }
    }
}