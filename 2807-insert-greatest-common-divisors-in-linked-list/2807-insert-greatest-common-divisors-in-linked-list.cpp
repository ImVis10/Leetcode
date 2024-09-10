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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head) return NULL;
        
        if (!head->next) return head;
        
        ListNode* curr, *next;
        
        curr = head;
        
        while (curr->next) {
            next = curr->next;
            int gcdVal = gcd(curr->val, next->val);
            ListNode* gcdNode = new ListNode(gcdVal);
            curr->next = gcdNode;
            gcdNode->next = next;
            curr = curr->next->next;
        }
        return head;
        
    }
};