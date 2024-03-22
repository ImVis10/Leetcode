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
    bool isPalindrome(ListNode* head) {
        return recurse(head, head);
    }
private:
    bool recurse(ListNode* curr, ListNode* &tempHead) {
        if (curr) {
            if (!recurse(curr->next, tempHead)) return false;
            if (curr->val != tempHead->val) return false;
            tempHead = tempHead->next;
        }
        return true;
    }
};