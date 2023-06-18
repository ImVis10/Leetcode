class Solution {
public:
    int beautySum(string s) {
        int len = s.length();
        int res = 0;
        for (int i = 0; i < len; i++) {
            unordered_map<char, int> map;
            for (int j = i; j < len; j++) {
                map[s[j]]++;
                res += getBeauty(map);
            }
        }
        return res;
    }
    
private:
    int getBeauty(unordered_map<char, int>& map) {
        int maxFreq = INT_MIN;
        int minFreq = INT_MAX;
        for (auto& entry : map) {
            maxFreq = max(maxFreq , entry.second);
            if (entry.second >= 1) {
                minFreq = min(minFreq, entry.second);
            }
        }
        return maxFreq - minFreq;
    }
};