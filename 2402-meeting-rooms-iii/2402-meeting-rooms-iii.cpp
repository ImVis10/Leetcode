class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> used; // pair<endtime, room>
        priority_queue<int, vector<int>, greater<int>> available;
        vector<int> count(n);
        // initally all the rooms are available
        for (int i = 0; i < n; ++i) {
            available.push(i);
        }
        for (auto& meeting : meetings) {
            long long start = meeting[0];
            long long end = meeting[1];
            // finish the meetings that have ended
            while (!used.empty() and start >= used.top().first) {
                int finishedRoom = used.top().second;
                used.pop();
                available.push(finishedRoom);
            }
            // if no rooms are available, get the one that ends ASAP and add it to available
            if (available.empty()) {
                auto nextAvailable = used.top(); 
                used.pop();
                end = nextAvailable.first + (end - start);
                available.push(nextAvailable.second); // push the room
            }
            
            // if rooms are available
            int room = available.top(); 
            available.pop();
            used.push({end, room});
            count[room]++;
        }
        
        // find the room with the maximum count of meetings
        int maxMeetings = 0, roomNumber = 0;
        for (int i = 0; i < n; i++) {
            if (count[i] > maxMeetings) {
                maxMeetings = count[i];
                roomNumber = i;
            }
        }
        return roomNumber;
    }
};