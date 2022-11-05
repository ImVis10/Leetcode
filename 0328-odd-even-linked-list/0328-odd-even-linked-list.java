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
        ListNode p1 = head, p2 = head.next;
        ListNode temp1 = p1, temp2 = p2;
        
        while (p1 != null  && p2 != null) {
            p1.next = p2.next;
            if (p1.next != null) {
             p1 = p1.next;   
            }            
//             if (p1 != null) {
                
//             }
            p2.next = p1.next;
            p2 = p2.next;
        }
        
        p1.next = temp2;
        
        return temp1;
    }
}