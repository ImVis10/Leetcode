class SeatManager {
    priority_queue<int, vector<int>, greater<int>> pq;
    int seat = 1;
public:
    SeatManager(int n) {
        
    }
    
    int reserve() {
        if (!pq.empty()) {
            int top = pq.top();
            pq.pop();
            return top;
        }
        return seat++;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */