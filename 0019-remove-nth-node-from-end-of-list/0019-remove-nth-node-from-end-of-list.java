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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        // Can be easily done in more than one pass and using extra space, but that's not my objective here.
        // To do this in a single pass and O(1) space, using two pointers.
        // Two pointers, as this is a linked list we can't directly jump to the given 'n' from the end of the list.
        // One pointer to reach the end of the list and the next one to get to nth position from the end of the list.
        /**Once the first pointer reaches nth node from the start, start the second pointer as well. So that once first pointer reaches end of the          list, second pointer reaches the node before the nth node from the end of the list**/
        ListNode p1 = head, p2 = head;
        int count = 0;
        for (int i = 1; i <= n ; i++) {
            p1 = p1.next;
        }
        // for cases where nth node from the end of a list of size n, there is no node before that as it is the first node, as the approach is to           // get the node before the node to be deleted.
        if (p1 == null) {
            return head.next;
        }
        while (p1.next != null) { // using the second pointer as reference, until it reaches end of the list
            p1 = p1.next;
            p2 = p2.next;
        }
        p2.next = p2.next.next;
        return head;
    }
}