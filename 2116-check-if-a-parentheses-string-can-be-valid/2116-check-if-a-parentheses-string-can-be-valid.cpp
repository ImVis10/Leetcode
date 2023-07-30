class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.length() & 1) return false;
        
        int canFlip = 0, open = 0, close = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (locked[i] == '0') {
                canFlip++;
            } else if (s[i] == '(') {
                open++;
            } else {
                close++;
            }
            if (canFlip < close - open) {
                return false;
            }
        }
                
        canFlip = 0, open = 0, close = 0;
        
        for (int i = s.length() - 1; i >= 0; i--) {
            if (locked[i] == '0') {
                canFlip++;
            } else if (s[i] == '(') {
                open++;
            } else {
                close++;
            }
            if (canFlip < open - close) {
                return false;
            }
        }
        return true;
    }
};