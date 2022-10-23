/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        // using extra memory for now.
        Set<ListNode> set = new HashSet<>();
        ListNode p = head;
        while (p != null) {
            if (!set.add(p)) {
                return p;
            }
            p = p.next;
        }
        return null;
    }
    // todo: without extra space.
    /**
    To check whether there is a cycle present. If both the pointers meet(using slow & fast pointer approach), it means that there is a cycle. But the objective of this problem is not only to detect the cycle but also to return the start node of the cycle if there is any, */
}