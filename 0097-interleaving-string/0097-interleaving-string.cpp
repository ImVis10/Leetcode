class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length();
        vector<vector<int>> cache(m + 1, vector<int>(n + 1, -1));
        return recurse(0, s1, 0, s2, s3, cache);
    }
private:
    bool recurse(int idx1, string s1, int idx2, string s2, string s3, vector<vector<int>>& cache) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        if (idx1 == s1.length() and idx2 == s2.length()) {
            return true;
        }
        
        if (cache[idx1][idx2] != -1) {
            return cache[idx1][idx2];
        }
        
        if (idx1 < s1.length() and s1[idx1] == s3[idx1 + idx2] and recurse(idx1 + 1, s1, idx2, s2, s3, cache)) {
            return true;
        }
        
        if (idx2 < s2.length() and s2[idx2] == s3[idx1 + idx2] and recurse(idx1, s1, idx2 + 1, s2, s3, cache)) {
            return true;
        }
        
        return cache[idx1][idx2] = 0;
    }
};