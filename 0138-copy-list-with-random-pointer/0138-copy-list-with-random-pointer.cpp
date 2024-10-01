/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // if (!head) return NULL;
        // if (ll.find(head) == ll.end()) { // if node not cloned yet
        //     Node* node = new Node(head->val, NULL, NULL);
        //     ll[head] = node;
        //     node->next = this->copyRandomList(head->next); // clone the next node
        //     node->random = this->copyRandomList(head->random); // clone the random node
        // }
        // return ll[head];
        
        // WITHOUT USING EXTRA SPACE
        // INSTEAD OF A MAP, WE CAN TWEAK THE ORIGINAL LINKED LIST TO HAVE THE CLONED NODE NEXT TO THE ORIGINAL NODE
        
        if (!head) return nullptr;
        Node* ptr = head;
        while (ptr) {
            Node* newNode = new Node(ptr->val, nullptr, nullptr);
            newNode->next = ptr->next;
            ptr->next = newNode;
            ptr = newNode->next;
        }
        // link random pointers
        ptr = head;
        while (ptr) {
            ptr->next->random = ptr->random ? ptr->random->next : nullptr;
            ptr = ptr->next->next;
        }
        // link next pointers
        Node* p1 = head;
        Node* p2 = head->next;
        Node* res = head->next;
        while (p1) {
            p1->next = p1->next->next;
            p2->next = p2->next ? p2->next->next : nullptr;
            p1 = p1->next;
            p2 = p2->next;
        }
        return res;
    }
// private:
//     unordered_map<Node*, Node*> ll;
};