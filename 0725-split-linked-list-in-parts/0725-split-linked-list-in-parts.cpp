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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr = head;
        int cnt = 0;
        while (curr) {
            curr = curr->next;
            cnt++;
        }

        curr = head;
        
        int window = cnt / k, rem = cnt % k;
        
        ListNode* prev = curr;

        vector<ListNode*> res;

        while (k--) {
            ListNode* newHead = curr;
            int currWindow = rem > 0 ? window + 1 : window; rem--;
            int itr = 0;
            while (itr++ < currWindow) {
                prev = curr;
                if (curr)
                    curr = curr->next;
                // itr++;
            }
            if (prev)
                prev->next = nullptr;
            res.push_back(newHead);
            
        }
        return res;
    }
};