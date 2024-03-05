class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size(), res = 0, low = 0, high = n - 1;
        
        if (n == 0) return res;
        
        sort(tokens.begin(), tokens.end());
        
        if(power < tokens[0]) return res;
        
        while (low <= high) {
            if (power >= tokens[low]) {
                power -= tokens[low++];
                res++;
            } else {
                if (low == high and power < tokens[high--]) continue;
                power += tokens[high--];
                res = max(0, res - 1);
            }
        }
        return res;
    }
};