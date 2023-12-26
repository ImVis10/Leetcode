class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        remove(mp[key]);
        insert(mp[key]);
        return mp[key]->val;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            remove(mp[key]);
            delete mp[key];
        } else if (mp.size() == cap) {
            Node* lru = head->next;
            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }
        mp[key] = new Node(key, value);
        insert(mp[key]);
    }
private:
    int cap;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mp;

    void remove(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insert(Node* node) {
        Node* beforeTail = tail->prev;
        beforeTail->next = node;
        node->prev = beforeTail;

        node->next = tail;
        tail->prev = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */