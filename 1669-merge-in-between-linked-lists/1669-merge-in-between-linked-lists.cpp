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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* nodeBeforeA = list1, *lastNodeInB = list2, *nodeAfterB;
        int dist = b - a;
        while (a-- > 1) {
            nodeBeforeA = nodeBeforeA->next;
        }
        nodeAfterB = nodeBeforeA->next;
        nodeBeforeA->next = list2;
        while (dist-- >= 0) {
            nodeAfterB = nodeAfterB->next;
        }
        while (lastNodeInB->next) {
            lastNodeInB = lastNodeInB->next;
        }
        lastNodeInB->next = nodeAfterB;
        return list1;
    }
};