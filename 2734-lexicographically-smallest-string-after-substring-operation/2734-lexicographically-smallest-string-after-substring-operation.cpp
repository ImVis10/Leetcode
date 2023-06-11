class Solution {
public:
    string smallestString(string s) {
        int n = s.length();
        int start = 0, cnt = 0;
        
        while (start < n - 1 && s[start] == 'a') {
            start += 1; 
        }
        
        for (int i = start; i < n; i++) {
            if (s[i] == 'a') {
                start = i;
                break;
            }
            cnt++;
            s[i]--;
        }
        if (cnt == 0) {
            s[start] = 'z';
        }
        return s;
    }
};