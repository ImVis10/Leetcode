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
    void reorderList(ListNode* head) {
        // reach until mid
        ListNode* mid = findMidPoint(head);

        
        // reverse after mid
        ListNode* head2 = reverseList(mid);
        
        
        while (head && head2) {
            ListNode* next1 = head->next;
            ListNode* next2 = head2->next;
            head->next = head2;
            head2->next = next1;
            head = next1;
            head2 = next2;
        }
    }
    
private:
    ListNode* findMidPoint(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode* mid = slow->next;
        slow->next = NULL;
        return mid;
    }
    
    ListNode* reverseList(ListNode* head) {
        if (!head) return NULL;
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next;
        
        while (curr) {
            next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next;
        }
        return prev;
    }
};