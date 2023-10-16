class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string res = "";
        int n = s.length();
        int numOnes = 0, resLen = INT_MAX;
        
        for (int start = 0, end = 0; end < n; end++) {
            if (s[end] == '1') numOnes++;
            while (numOnes == k) {
                if (end - start + 1 < resLen || (resLen == end - start + 1 && s.substr(start, resLen) < res)) {
                    resLen = end - start + 1;
                    res = s.substr(start, resLen);
                }
                if (s[start++] == '1') numOnes--;
            }
        }
        return res;
    }
};