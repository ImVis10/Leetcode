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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> mp;
        ListNode* temp = new ListNode(0, head);
        int prefixSum = 0;
        
        ListNode* node = temp;
        while (node) { // if we encounter a prefixSum that we have already seen, it means that the nodes before that sum to 0...
            prefixSum += node->val;
            mp[prefixSum] = node;
            node = node->next;
        }
        
        prefixSum = 0;
        node = temp;
        while (node) { 
            prefixSum += node->val;
            node->next = mp[prefixSum]->next; // so skip to the next node
            node = node->next;
        }
        return temp->next;
    }
};