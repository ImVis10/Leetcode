class Solution {
public:
    int minDeletions(string s) {
        sort(s.begin(), s.end());
        
        set<int> set;
        
        int cnt = 1, res = 0;
        
        for (int i = 1; i <= s.length(); i++) {
            if (i < s.length() && s[i] == s[i - 1]) {
                cnt++; // frequency of a specific char until that point of time
            } else { // if it's a different char from the previous char
                while (set.count(cnt)) { // as long as a different char with same freq is present
                    if (cnt != 0) {
                        cnt--;
                        res++;
                    }
                }
                if (cnt > 0) {
                    set.insert(cnt);
                }
                cnt = 1; // reset the frequency to 1 so that it can be used by the new char in the right way
            }
        }
        return res;
    }
};