class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : arr) {
            freq[num]++;
        }
        for (auto& [num, cnt] : freq) {
            pq.push(cnt);
        }
        while (k > 0) {
            k -= pq.top();
            if (k >= 0) pq.pop();
        }
        return pq.size();
    }
};