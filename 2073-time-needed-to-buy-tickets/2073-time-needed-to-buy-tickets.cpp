class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size(), t = 0;
        
        for (int i = 0; i < n; i++) {
            if (i <= k) {
                if (tickets[i] >= tickets[k]) t += tickets[k];
                else t += tickets[i];
            } else {
                if (tickets[i] >= tickets[k]) t += tickets[k] - 1;
                else t += tickets[i];
            }
        }
        return t;
    }
};