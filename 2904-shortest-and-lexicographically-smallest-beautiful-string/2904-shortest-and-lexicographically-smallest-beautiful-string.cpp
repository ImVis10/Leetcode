class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string res = "";
        int n = s.length(), cnt = 0;
        int resLen = INT_MAX;
        int i = 0, j = 0;
        
        for (i = 0, j = 0; j < n; j++) {
            if (s[j] == '1') cnt++;
            while (cnt == k) {
                if (j - i + 1 < resLen || (j - i + 1 == resLen && s.substr(i, resLen) < res)) {
                    resLen = j - i + 1;
                    res = s.substr(i, resLen);
                }
                if (s[i] == '1') cnt--;
                i++;
            }
        }
        return res;
    }
};