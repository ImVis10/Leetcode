class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size(), t = 0;
        
        for (int i = 0; i < n; i++) {
            if (tickets[i] >= tickets[k]) {
                t += i <= k ? tickets[k] : tickets[k] - 1;
            } else {
                t += tickets[i];
            }
        }
        return t;
    }
};