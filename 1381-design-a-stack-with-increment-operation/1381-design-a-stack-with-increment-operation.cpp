class CustomStack {
    vector<int> stk;
    int cnt, capacity;
public:
    CustomStack(int maxSize) {
        capacity = maxSize;
        cnt = 0;
    }
    
    void push(int x) {
        if (cnt == capacity) return;
        stk.push_back(x);
        cnt++;
    }
    
    int pop() {
        if (stk.empty()) return -1;
        cnt--;
        int res = stk[stk.size() - 1];
        stk.pop_back();
        return res;
    }
    
    void increment(int k, int val) {
        k = min(k, (int) stk.size());
        for (int i = 0; i < k; i++) {
            stk[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */