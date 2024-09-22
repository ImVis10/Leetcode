class Solution {
public:
    int findKthNumber(int n, int k) {
        long long curr = 1;
        int idx = 1;
        while (idx < k) {
            int steps = numNodes(curr, n);
            if (idx + steps <= k) {
                curr += 1;
                idx += steps;
            } else {
                curr *= 10;
                idx += 1;
            }
        }
        return curr;
    }
private:
    int numNodes(long long curr, int n) {
        long long nei = curr + 1, cnt = 0;
        while (curr <= n) {
            if (nei > n + 1) nei = n + 1;
            cnt += nei - curr;
            curr *= 10;
            nei *= 10;
        }
        return cnt;
    }
};