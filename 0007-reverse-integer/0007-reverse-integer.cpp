class Solution {
public:
    int reverse(int x) {
        int res = 0;
        cout << INT_MAX << endl;
        
        while (x != 0) {
            if (res > INT_MAX/10 || res < INT_MIN/10) {
                return 0;
            }
            int rem = x % 10;
            int temp = (res * 10) + rem;
            res = temp;
            x /= 10;
        }
        return res;
    }
};