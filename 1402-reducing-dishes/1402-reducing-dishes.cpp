class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        // so the gist is that only dishes that give more satisfaction must be cooked
        // and among the satisfied dishes - start with small satisaction and end with highest satisfaction
        // which will MAXIMIZE like-time coefficient
        
        sort(begin(satisfaction), end(satisfaction));
        
        int n = satisfaction.size();
        int res = 0, satisfactionSoFar = 0;
        
        for (int i = n - 1; i >= 0 && satisfaction[i] + satisfactionSoFar > 0; i--) {
            satisfactionSoFar += satisfaction[i];
            res += satisfactionSoFar;
        }
        return res;
    }
};