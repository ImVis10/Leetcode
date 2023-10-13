class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();
        
        if (m < n) return "";
        
        unordered_map<char, int> freqT;
        
        for (char ch : t) {
            freqT[ch]++;
        }
        
        int charsFromT = 0, minWindow = INT_MAX, windowStartsAt = 0;
        for (int i = 0, j = 0; j < m; j++) {
            if (--freqT[s[j]] >= 0) {
                charsFromT++;
            }
            while (charsFromT == n) {
                if (j - i + 1 < minWindow) {
                    minWindow = j - i + 1;
                    windowStartsAt = i;
                }
                // the next lines of code is to minimize the window i.e., to shrink the window
                if (++freqT[s[i++]] > 0) charsFromT--; // count of chars not from t would be negative, if it's greater than 0, it means that the characters are from t, so we remove 1 from them, as we are incrementing the count.We don't want to count it twice. 
            }
        }
        return minWindow == INT_MAX ? "" : s.substr(windowStartsAt, minWindow);
    }
};