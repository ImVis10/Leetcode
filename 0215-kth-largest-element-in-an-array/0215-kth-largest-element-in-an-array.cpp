class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq; // max heap
        
        for (auto& num : nums) {
            pq.push(num);
        }
        
        int count = 0;
        int res = INT_MIN;
        while (--k >= 1) pq.pop();
        return pq.top();
    }
};