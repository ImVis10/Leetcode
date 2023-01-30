class Solution {
public:
    int minOperations(vector<string>& logs) {
        int res = 0;
        for (string op : logs) {
            if(isalpha(op[0]) || isdigit(op[0])) {
                res++;
            }
            if (op == "../" && res > 0) {
                res--;
            }
            if (op == "./") {
                continue;
            }
        }
        return res;
    }
};