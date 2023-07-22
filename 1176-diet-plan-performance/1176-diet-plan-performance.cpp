class Solution {
public:
    int dietPlanPerformance(vector<int>& c, int k, int lower, int upper) {
        int n = c.size();
        int sum = 0, cnt = 0, res = 0;
        for (int i = 0; i < n; i++) {
            sum += c[i];
            cnt++;
            
            if (cnt == k) {
                res += sum < lower ? -1 : sum > upper ? 1 : 0;
                cnt--;
                sum -= c[i - k + 1];
            }
        }
        return res;
    }
};