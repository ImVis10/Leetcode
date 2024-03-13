class Solution {
public:
    int pivotInteger(int n) {
        unordered_map<int, int> mp;
        int prefixSum = 0;
        for (int num = 1; num <= n; num++) {
            prefixSum += num;
            mp[num] = prefixSum;
        }
        prefixSum = 0;
        for (int num = n; num > 0; num--) {
            prefixSum += num;
            if (mp[num] == prefixSum) return num;
        }
        return -1;
    }
};