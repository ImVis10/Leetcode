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
    int pairSum(ListNode* head) {
        int res = 0;
        
        ListNode* fastptr;
        ListNode* slowptr;
        fastptr = head;
        slowptr = head;
        
        while (fastptr != nullptr) {
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        }
        
        stack<int> stack;
        
        while (slowptr != nullptr) {
            stack.push(slowptr->val);
            slowptr = slowptr->next;
        }
        
        ListNode* ptr = head;
        
        while (!stack.empty()) {
            int ele = stack.top();
            stack.pop();
            int sum = ptr->val + ele;
            res = max(sum, res);
            ptr = ptr->next;
        }
        return res;
    }
};