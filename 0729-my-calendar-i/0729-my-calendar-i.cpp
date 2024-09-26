class MyCalendar {
    vector<pair<int, int>> bookings;
public:
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        for (auto& [s, e] : bookings) {
            if (max(start, s) < min(end, e)) { // checks for overlap between new event and existing event
                return false;
            }
        }
        bookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */