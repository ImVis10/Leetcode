class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.length(), n = goal.length();
        if (m != n) return false;
        
        string temp = s + s;
        
        return temp.find(goal) < 2 * m;
    }
};