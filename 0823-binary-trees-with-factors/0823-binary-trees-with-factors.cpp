class Solution {
    const int MOD = 1e9 + 7;
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_set<int> set(arr.begin(), arr.end());
        
        unordered_map<int, int> cache;
        
        for (int num : arr) cache[num] = 1;
        
        for (int i : arr) { // trying to find the factors of i
            for (int j : arr) { // can j be a factor?
                /**
                we want to see if a number can be expressed as the product of two numbers from the array arr. So when j (which represents one of the potential factors) becomes larger than the square root of i, its counterpart (the other factor, i/j) would've already been examined in previous iterations. We can then skip further checks**/
                if (j > sqrt(i)) break;
                if (i % j == 0 && set.find(i / j) != set.end()) {
                    // cache[j] gives the number of trees that can be formed with j as the root,
                    long long numTrees = (long long) cache[j] * cache[i / j];
                    if (i / j == j) {
                        cache[i] = (cache[i] + numTrees) % MOD;
                    } else {
                        cache[i] = (cache[i] + numTrees * 2) % MOD;
                    }
                }
            }
        }
        
        int res = 0;
        
        for (auto& [k, v] : cache) {
            res = (res + v) % MOD;
        }
        return res;
    }
};