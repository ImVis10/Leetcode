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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        // stack<int> s3; // MLE if output stack is used, so should use prev, curr, next approach
        ListNode* res = nullptr;
        int carry = 0;
        while (l1) {
            s1.push(l1->val); 
            l1 = l1->next;
        }
        
        while (l2) {
            s2.push(l2->val); 
            l2 = l2->next;
        }
        
        while (!s1.empty() || !s2.empty() || carry > 0) {
            int t1 = s1.empty() ? 0 : s1.top();
            int t2 = s2.empty() ? 0 : s2.top();
            
            int sum = t1 + t2 + carry;
            carry = sum > 9 ? sum / 10 : 0;
            
            ListNode* currDigitSum = new ListNode(sum % 10);
            currDigitSum->next = res;
            res = currDigitSum;
            
            if (!s1.empty()) s1.pop();
            if (!s2.empty()) s2.pop();
        }
        return res;
    }    
};