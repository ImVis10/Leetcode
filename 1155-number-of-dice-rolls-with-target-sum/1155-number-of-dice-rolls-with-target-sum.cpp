class Solution {
    const int MOD = 1e9 + 7;
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> cache(n + 1, vector<int>(target + 1, -1));
        return recurse(n, k, target, cache);
    }
private:
    int recurse(int n, int k, int target, vector<vector<int>>& cache) {
        if (n < 0 or target < 0) return 0;
        if (n == 0 and target == 0) return 1;
        if (cache[n][target] != -1) return cache[n][target];
        int nWays = 0;
        for (int faceVal = 1; faceVal <= k; faceVal++) {
            if (faceVal <= target) nWays = (nWays + recurse(n - 1, k, target - faceVal, cache)) % MOD;
        }
        return cache[n][target] = nWays;
    }
};