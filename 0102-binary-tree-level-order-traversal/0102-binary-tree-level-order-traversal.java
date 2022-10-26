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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new LinkedList<>();
        if (root == null) {
            return res;
        }
        // queue instead of stack as we need to add them to the result list in order from left to right.
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        while (!queue.isEmpty()) {
            int levelSize = queue.size();
            List<Integer> listForEachLevel = new LinkedList<>();
            for (int i = 0; i < levelSize; i++) { // can't use queue.size() directly here as nodes are added to queue at every iteration. So store it in a variable prior to iterations, so each level is visited the number of times it is supposed to be visited i.e. for the no. of nodes in that level.
                TreeNode visited = queue.poll();
                listForEachLevel.add(visited.val);

                if (visited.left != null) {
                    queue.add(visited.left); // if there are children to the current node being visited, add them to the queue, so that they can be added to the result list when their turn arrives.
                }

                if (visited.right != null) {
                    queue.add(visited.right);
                }
            }
            res.add(listForEachLevel);
        }
        return res;
    }
}