class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        
        if (n % 2) return false;
        
        int canFlip = 0, open = 0, close = 0;
        
        for (int i = 0; i < n; i++) {
            if (locked[i] == '0') canFlip++;
            else if (s[i] == '(') open++;
            else close++;
            if (close > canFlip + open) return false;
        }
        
        canFlip = 0, open = 0, close = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            if (locked[i] == '0') canFlip++;
            else if (s[i] == '(') open++;
            else close++;
            if (open > canFlip + close) return false;
        }
        
        return true;
    }
};