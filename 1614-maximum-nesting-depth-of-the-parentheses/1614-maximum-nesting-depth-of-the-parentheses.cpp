class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int res = 0;
        
        for (char ch : s) {
            if (ch == '(') {
                depth++;
                res = max(res, depth);
            } else if (ch == ')') {
                depth--;
            }
        }
        return res;
    }
};