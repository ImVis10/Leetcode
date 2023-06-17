class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s == goal) {
            return true;
        }
        
        string temp = s;
        
        s = removespace(s);
        goal = removespace(goal);
        
        int len = s.length();

        for (int i = 0; i < len; i++) {
            if (s != goal) {
                s = temp;
                reverse(s.begin(), s.end());
                reverse(s.begin(), s.begin() + len - i - 1);
                reverse(s.begin() + len - i - 1, s.end());
            } else {
                return true;
            }
        }
        return false;
    }

private:
    string removespace(string s) {
        //traversing the string
        for (int i = 0; i < s.length(); i++) {
            if (!(s[i] >= 'a' && s[i] <= 'z')) {
                //using in-built function to erase element
                s.erase(s.begin() + i);
                i--;
            }
        }
        return s;
    }
};