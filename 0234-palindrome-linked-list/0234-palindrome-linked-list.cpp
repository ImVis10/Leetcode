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
    ListNode *tempHead;
public:
    bool isPalindrome(ListNode* head) {
        tempHead = head;
        return recurse(head);
    }
private:
    bool recurse(ListNode* curr) {
        if (curr) {
            if (!recurse(curr->next)) return false;
            if (curr->val != tempHead->val) return false;
            tempHead = tempHead->next;
        }
        return true;
    }
};