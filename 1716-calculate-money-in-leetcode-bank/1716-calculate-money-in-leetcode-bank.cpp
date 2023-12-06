class Solution {
public:
    int totalMoney(int n) {
        if (n <= 7) return n * (n + 1) / 2;
        
        int q = n / 7, rem = n % 7;
        
        int res = 0, sum = 28, temp = q;;
        
        while (temp--) {
            res += sum;
            sum += 7;
        }
        // cout << res;
        int start = q + 1, end = q + rem;
        // cout << start << " " << end;
        for (int num = start; num <= end; num++) res += num;
        
        return res;
    }
};