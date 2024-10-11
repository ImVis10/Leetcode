class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        int targetArrival = times[targetFriend][0]; // this works as arrival is distinct for each friend
        sort(times.begin(), times.end());
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int chair = 0;
        set<int> chairs;
        for (auto& time : times) {
            int start = time[0], end = time[1];
            while (!pq.empty() and pq.top().first <= start) {
                chairs.insert(pq.top().second);
                pq.pop();
            }
            int currChair;
            if (!chairs.empty()) {
                currChair = *chairs.begin();
                chairs.erase(chairs.begin());
            } else {
                currChair = chair++;
            }
            pq.push({end, currChair});
            if (start == targetArrival) return currChair;
        }
        return 0;
    }
};