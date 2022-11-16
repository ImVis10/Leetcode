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
    public boolean isPalindrome(ListNode head) {
        
        if(head == null) return false;
        
        Stack<Integer> stack = new Stack<>();
        boolean isPalindrome = false;
        
        ListNode node = head;
        while (node != null) {
            stack.push(node.val);
            node = node.next;
        }
        
        node = head;
        
        while (node != null) {
            if (stack.pop() == node.val) {
                isPalindrome = true;
            } else {
                isPalindrome = false;
                break;
            }
            node = node.next;
        }
        
        return isPalindrome;
    }
}