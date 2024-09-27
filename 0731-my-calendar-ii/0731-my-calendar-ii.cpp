class MyCalendarTwo {
    vector<pair<int, int>> overlapping;
    vector<pair<int, int>> nonOverlapping;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for (auto& [s, e] : overlapping) {
            if (!(end <= s or start >= e)) {
                return false;
            }
        }
        
        for (auto&[s, e] : nonOverlapping) {
            if (!(end <= s or start >= e)) {
                overlapping.push_back({max(s, start), min(e, end)});
            }
        }
        nonOverlapping.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */