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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head or left == right) return head;
        int pos = 1;
        ListNode* curr = head;
        ListNode* prev = nullptr, *next = nullptr, *prevToReversedLL = curr, *tailOfReversedLL = nullptr;        
        
        while (pos < left) {
            prev = curr;
            curr = curr->next;
            pos++;
        }

        prevToReversedLL = prev;
        tailOfReversedLL = curr;

        while (pos >= left and pos <= right) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            pos++;
        }
        if (prevToReversedLL) {
            prevToReversedLL->next = prev;
        } else {
            head = prev;
        }
        if (tailOfReversedLL) tailOfReversedLL->next = curr;
        return head;
    }
};