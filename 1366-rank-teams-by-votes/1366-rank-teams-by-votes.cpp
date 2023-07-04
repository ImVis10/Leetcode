#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int numVotes = votes.size(); // for each voter
        
        if (numVotes == 1) {
            return votes[0];
        }
        
        int numTeams = votes[0].length();
        
        vector<vector<int>> rank(numTeams, vector<int>(26, 0));
        
        for (auto vote : votes) {
            for (int i = 0; i < numTeams; i++) {
                rank[i][vote[i] - 'A']++;
            }
        }
        
        string res = votes[0];
        
        sort(res.begin(), res.end(), [&](char x, char y) {
            for (int i = 0; i < numTeams; i++) {
                if (rank[i][x - 'A'] == rank[i][y - 'A']) continue; // if num votes are same, continue as we've already sorted in asc order
                return rank[i][x - 'A'] > rank[i][y - 'A'];
            }
            return x < y;
        });
        return res;
    }
};