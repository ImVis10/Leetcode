class Solution {
public:
    int findKthNumber(int n, int k) {
        long long curr = 1;
        int idx = 1;
        while (idx < k) {
            int steps = numNodes(curr, n);
            if (idx + steps <= k) { // kth smallest is not in that subtree
                curr += 1; // so move to right
                idx += steps; // num of nodes bypassed while moving to right
            } else { // kth smallest is in that subtreee
                curr *= 10; // move down
                idx += 1; // number of nodes covered while moving down
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