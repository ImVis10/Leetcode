class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq; // max heap
        for (int num : nums) pq.push(num);
        
        long long int score = 0;
        
        while (k--) {
            int maxVal = pq.top(); pq.pop();
            score += maxVal;
            int replace = ceil(maxVal / 3.0);
            pq.push(replace);
        }
        return score;
    }
};