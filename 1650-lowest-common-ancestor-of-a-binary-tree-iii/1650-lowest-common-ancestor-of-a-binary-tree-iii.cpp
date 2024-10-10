/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        // It is guarenteed that both p, q exist in the tree
        // we also have a pointer to parent
        // so its just about traversing to the parents of both the nodes
        // if in the traversal of q to parent, we find a node that is already visited, that is the LCA
        
        set<Node*> visited;
        
        while (p) {
            visited.insert(p);
            p = p->parent;
        }
        
        while (q) {
            if (visited.count(q)) {
                return q;
            }
            q = q->parent;
        }
        return NULL;

        // without using extra space
        // using two runners on the circular track concept
        /**
        Node* a = p, *b = q;
        while (a != b) {
            a = a == nullptr ? q : a->parent;
            b = b == nullptr ? p : b->parent;    
        }
        return a;
        **/
    }
};
