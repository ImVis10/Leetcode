class Solution {
public:
    int totalFruit(vector<int>& f, int k = 2) {
        int n = f.size();
        int res = 0;
        unordered_map<int, int> freq;
        for (int i = 0, j = 0; j < n; j++) {
            freq[f[j]]++;
            if (freq.size() > k) {
                if (--freq[f[i]] == 0) freq.erase(f[i]);
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};