class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length(), res = 0;
        int start = 0, end = 1;
        
        for (end = 1; end < n; end++) {
            if (colors[start] == colors[end]) {
                if (neededTime[start] < neededTime[end]) {
                    res += neededTime[start];
                    start = end;
                } else {
                    res += neededTime[end];
                }
            } else {
                start = end;
            } 
        }
        return res;
    }
};