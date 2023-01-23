class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this-> k = k;
        for (int num : nums) {
            minHeap.push(num);
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        
        while (minHeap.size() > k) {
            minHeap.pop();
        }
        return minHeap.top();
    }

private:
    priority_queue <int, vector<int>, greater<int>> minHeap;
    int k; //  global variable so that it can be used by add
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */