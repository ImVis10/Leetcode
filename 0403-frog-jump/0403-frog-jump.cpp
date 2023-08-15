class Solution {
    unordered_map<int, int> stoneMap;
    int cache[2001][2001];

public:
    bool canCross(vector<int>& stones) {
        for (int i = 0; i < stones.size(); i++) {
            stoneMap[stones[i]] = i;
        }
        
        // vector<vector<int>> cache(stones.size() + 1, vector<int>(stones.size() + 1, -1));
        memset(cache, -1, sizeof(cache));
        return recurse(0, stones, 0); // two changing parameters 1. index of stone 2. size of the prev jump
    }
private:
    bool recurse(int idx, vector<int>& stones, int prevJump) {
        if (idx == stones.size() - 1) {
            return true;
        }
        
        if (cache[idx][prevJump] != -1) {
            return cache[idx][prevJump];
        }
        
        bool res = false;
        
        for (int nextJump = prevJump - 1; nextJump <= prevJump + 1; nextJump++) {
            if (nextJump > 0 && stoneMap.find(stones[idx] + nextJump) != stoneMap.end()) {
                res = res || recurse(stoneMap[stones[idx] + nextJump], stones, nextJump);
            }
        }
        return cache[idx][prevJump] = res;
    }
};