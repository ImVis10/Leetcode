class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;
    
    Node(int key, int val) {
        this->key = key;
        this->val = val;
        this->next = NULL;
        this-> prev = NULL;
    }
};

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
        start = new Node(0, 0); // dummy node to indicate start
        end = new Node(0, 0); // dummy node to indicate end
        
        start->next = end;
        end->prev = start;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        // move the Node to the most recently used part of the list i.e. to the right, so remove first and then insert
        remove(cache[key]);
        insert(cache[key]);
        return cache[key]->val;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            delete node; // free the allocated memory
        }
        
        cache[key] = new Node(key, value);
        insert(cache[key]);
        
        if (cache.size() > cap) {
            Node* lru = start->next;
            remove(lru);
            cache.erase(lru->key); // erase the entry from the map
            delete lru; // free the allocated memory
        }
    }
private:
    unordered_map<int, Node*> cache;
    Node* start;
    Node* end;
    int cap;
    
    void remove(Node* node) {
        Node* next = node->next;
        Node* prev = node->prev;
        
        next->prev = prev;
        prev->next = next;
    }
    
    void insert(Node* node) {
        Node* prev = end->prev;
        
        node->next = end;
        node->prev = prev;
        
        prev->next = node;
        end->prev = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */