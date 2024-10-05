class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int res = 0;
        unordered_map<int, int> freq;
        for (int& age : ages) freq[age]++;
        for (auto& [x, cnt1] : freq) {
            for (auto& [y, cnt2] : freq) {
                if (request(x, y)) {
                    res += cnt1 * (cnt2 - (x == y ? 1 : 0));
                }
            }
        }
        return res;
    }
private:
    bool request(int x, int y) {
        return !(y <= (0.5 * x) + 7 or y > x or (y > 100 and x  < 100));
    }
};