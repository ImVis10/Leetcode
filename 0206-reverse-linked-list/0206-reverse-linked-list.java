/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        if (head == null) {
            return null;
        }
        
        ListNode curr = head;
        ListNode prev = null;
        ListNode next;
        
        while (curr != null) {
            // first getting the next node to visit as this node's next should point to the previous as we want to reverse the list
            next = curr.next;
            // pointing the node's next pointer to the previous node.
            curr.next = prev;
            
            // to repeat the same operation for the rest of the nodes in the list.
            // as the iteration is to be moved to next node, point prev to curr and curr to next;
            prev = curr;
            curr = next;
        }
        return prev;
    }
}