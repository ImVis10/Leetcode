/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public List<Integer> preorder(Node root) {
        // each group of children (each level) is seperated by null
        // preorder traversal -- root first and then children. So DFT can be used.
        List<Integer> res = new ArrayList<>();
        if (root == null) {
            return res;
        }
        Stack<Node> stack = new Stack<>();
        stack.push(root);
        while (!stack.isEmpty()) {
            Node visited = stack.pop();
            res.add(visited.val);
            for (int i = visited.children.size() - 1; i >= 0; i--) {
                stack.push(visited.children.get(i));
            }
        }
        return res;
    }
}