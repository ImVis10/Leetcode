class Node {
public:
    int val;
    Node* prev;
    Node* next;
    
    Node(int val) {
        this->val = val;
        this->prev = nullptr;
        this->next = nullptr;
    }
};


class MyCircularDeque {
    int cnt, sz;
    Node* head;
    Node* rear;
public:
    MyCircularDeque(int k) {
        cnt = 0;
        sz = k;
        head = nullptr;
        rear = nullptr;
    }
    
    bool insertFront(int value) {
        if (cnt >= sz) {
            return false;
        }
        Node* newNode = new Node(value);
        if (!head and !rear) {
            head = newNode;
            rear = newNode;
        } else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode; 
        }
        cnt++;
        return true;
    }
    
    bool insertLast(int value) {
        if (cnt >= sz) {
            return false;
        }
        Node* newNode = new Node(value);
        if (!head and !rear) {
            head = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode; 
        }
        cnt++;
        return true;
    }
    
    bool deleteFront() {
        if (cnt == 0){
            return false;
        }
        if (head->next) {
            head = head->next;
            head->prev = nullptr;
        } else {
            head = nullptr;;
            rear = nullptr;
        }
        cnt--;
        return true;
    }
    
    bool deleteLast() {
         if (cnt == 0){
            return false;
        }
        if (rear->prev) {
            rear = rear->prev;
            rear->next = nullptr;
        } else {
            rear = nullptr;
            head = nullptr;
        }
        cnt--;
        return true;       
    }
    
    int getFront() {
        return cnt == 0 ? -1 : head->val;
    }
    
    int getRear() {
        return cnt == 0 ? -1 : rear->val;
    }
    
    bool isEmpty() {
        return cnt == 0;
    }
    
    bool isFull() {
        return cnt == sz;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */