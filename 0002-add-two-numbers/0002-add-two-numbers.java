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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(0);
        ListNode res = head;
        int carry = 0;
        while (l1 != null || l2 != null || carry != 0) { // calculate until there are digits left to add or if there is a carry
            int sum = (l1 != null ? l1.val : 0) + (l2 != null ? l2.val : 0) + carry; // addition happens in the opposite direction when compared to normal addition 
            res.next = new ListNode(sum % 10); // getting the units digit if sum > 10
            carry = sum / 10; // getting the carry to forward while adding the next corresponding digits
            l1 = (l1 != null ? l1.next : l1); // forwarding the l1 pointer
            l2 = (l2 != null ? l2.next : l2); // forwarding the l2 pointer
            res = res.next; // forwarding the result pointer
        }
        return head.next;
    }
}