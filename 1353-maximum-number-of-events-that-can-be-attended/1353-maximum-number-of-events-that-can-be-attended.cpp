class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int numEvents = events.size();
        // we gotta attend maximum number of events
        // so we need to figure out one by one which event ends earliest
        // 2 buckets: completed events, not completed events
        // sort the not completed events based on end time
        // but first at the start, we have to sort all the events based on start time
        
        sort(events.begin(), events.end());
        
        int numDays = 0;
        for (auto& event : events)
            numDays = max(event[1], numDays);
        
        priority_queue<int, std::vector<int>, std::greater<int>> pq;
        int day = 1, cnt = 0, eventId = 0;
        
        while (day <= numDays) {
            if (eventId < numEvents && pq.empty()) { // if no events are  available for today, go to the next available event
                day = events[eventId][0];
            }
            while (eventId < events.size() && events[eventId][0] <= day) { // events starting from today are newly available. Add them to heap.
                pq.push(events[eventId][1]);
                eventId++;
            }
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }

            if (!pq.empty()) { // attend the event that'll end at the earliest
                pq.pop();
                cnt++;
            } else if (eventId >= events.size()) {
                break;
            }
            day++;
        }
        return cnt;
    }
};