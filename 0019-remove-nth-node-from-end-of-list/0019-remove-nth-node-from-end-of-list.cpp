/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    /**Once the first pointer reaches nth node from the start, start the second pointer as well. So that once first pointer reaches end of the list, second pointer reaches the node before the nth node from the end of the list**/
        ListNode* p1 = head, *p2 = head;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            p1 = p1->next;
        }
        
        if (p1 == NULL) return head->next;
        
        while (p1->next) {
            p1 = p1->next;
            p2 = p2->next;
        }
        // now we are at the previous node to the node to be deleted
        p2->next = p2->next->next;
        return head;
    }
};