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
    public ListNode oddEvenList(ListNode head) {
        
        if (head == null) {
            return null;
        }
        ListNode oddNode = head, evenNode = head.next;
        ListNode rememberEvenNode = evenNode;
        
        while (oddNode != null  && evenNode != null) {
            oddNode.next = evenNode.next;
            if (oddNode.next != null) {
             oddNode = oddNode.next;   
            }            
            evenNode.next = oddNode.next;
            evenNode = evenNode.next;
        }
        
        oddNode.next = rememberEvenNode;
        
        return head;
    }
}