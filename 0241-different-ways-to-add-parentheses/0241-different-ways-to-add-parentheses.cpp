class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        unordered_map<char, function<int(int, int)>> ops = {
            {'+', [](int x, int y) {
                return x + y;
            }},
            {'-', [](int x, int y) {
                return x - y;
            }},
            {'*', [](int x, int y) {
                return x * y;
            }}
        };
        
        function<vector<int>(int, int)> backtrack = [&](int l, int r) {
            vector<int> res;
            for (int i = l; i <= r; i++) {
                char op = expression[i];
                if (ops.count(op)) {
                    vector<int> num1 = backtrack(l, i - 1);
                    vector<int> num2 = backtrack(i + 1, r);
                    for (int n1 : num1) {
                        for (int n2 : num2) {
                           res.push_back(ops[op](n1, n2)); 
                        }
                    }
                }
            }
            if (res.empty()) {
                res.push_back(stoi(expression.substr(l, r - l + 1)));
            }
            return res;
        };
        return backtrack(0, expression.length() - 1);
    }
};