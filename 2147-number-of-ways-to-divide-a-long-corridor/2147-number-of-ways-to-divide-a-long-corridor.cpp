class Solution {
public:
    int numberOfWays(string corridor) {
        int n = corridor.length();
        
        int mod = 1e9 + 7;
        
        vector<int> seats;
        
        for (int i = 0; i < n; i++) {
            if (corridor[i] == 'S') seats.push_back(i);
        }
        
        int numSeats = seats.size();
        
        if (numSeats < 2 or numSeats & 1) return 0;
        
        int res = 1, secondSeat = 1; // second seat of current subarray
        
        while (secondSeat < numSeats - 1) {
            long long currComb = (long long)res * (seats[secondSeat + 1] - seats[secondSeat]);
            res = currComb % mod;
            secondSeat += 2;
        }
        return res % mod;
    }
};