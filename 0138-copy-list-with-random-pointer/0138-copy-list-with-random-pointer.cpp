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
        if (!head) return NULL;
        if (ll.find(head) == ll.end()) { // if node not cloned yet
            Node* node = new Node(head->val, NULL, NULL);
            ll[head] = node;
            node->next = this->copyRandomList(head->next); // clone the next node
            node->random = this->copyRandomList(head->random); // clone the random node
        }
        return ll[head];
    }
private:
    unordered_map<Node*, Node*> ll;
};