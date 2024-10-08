class Solution {
public:
    int minSwaps(string s) {
        stack<char> stk;
        double unbalanced = 0;
        for (char ch : s) {
            if (ch == '[') stk.push(ch);
            else {
                if (!stk.empty()) stk.pop();
                else unbalanced++;
            }
        }
        return (int) ceil(unbalanced / 2);
    }
};