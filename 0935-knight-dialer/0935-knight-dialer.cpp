class Solution {
public:
    int knightDialer(int n) {
        if (n == 1) return 10;
        
        int mod = 1e9 + 7;
        
        vector<vector<int>> moves = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
        
        vector<int> numWaysToLandAt(10, 1);
        
        for (int i = 1; i < n; i++) { // no. of ways to land on rest of the digits (except the first one) i.e. for n - 1 digits
            vector<int> nextLandAt(10);
            for (int num = 0; num < 10; num++) {
                for (int move : moves[num]) { // no. of ways to land on digit 'move'
                    nextLandAt[move] = (nextLandAt[move] + numWaysToLandAt[num]) % mod;
                }
            }
            numWaysToLandAt = nextLandAt;
        }
        int res = 0;
        for (int num : numWaysToLandAt) res = (res + num) % mod;
        return res;
    }
};