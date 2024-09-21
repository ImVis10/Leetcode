class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        int curr = 1;
        while (res.size() < n) {
            res.push_back(curr);
            if (curr * 10 <= n) {
                curr *= 10;
            } else {
                while (curr == n or curr % 10 == 9) {
                    curr /= 10;
                }
                curr += 1;
            }
        }
        return res;
    }
};