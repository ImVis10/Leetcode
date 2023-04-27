class SmallestInfiniteSet {
    unordered_set<int> set;
    priority_queue<int, vector<int>, greater<int>> pq;
    int currNum;
public:
    SmallestInfiniteSet() {
        currNum = 1;
    }
    
    int popSmallest() {
        int res = 0;
        
        if (!pq.empty()) {
            res = pq.top();
            pq.pop();
            set.erase(res);
        } else {
            res = currNum;
            currNum++;
        }
        return res;
    }
    
    void addBack(int num) {
        // if the num is not already present in the infinite set, add it to the set
        // but what if the set we defined does not have any elements in it
        if (currNum <= num || set.count(num)) {
            return;
        }
        
        pq.push(num);
        set.insert(num);
        
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */