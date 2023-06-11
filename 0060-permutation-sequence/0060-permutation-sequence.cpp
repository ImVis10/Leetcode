class Solution {
public:
    string getPermutation(int n, int k) {
        // write your code here
        string str = "";
        for (int i = 1; i <= n; i++) {
            str += to_string(i);
        }
        string res = str;
        for (int i = 1; i < k; i++) {
            // cout << res << endl;
            res = nextPermutation(res);
        }
        return res;
    }
private:
    string nextPermutation(string s) {
        int dip = -1;
        int n = s.length();
        
        for (int i = n - 2; i >=0; i--) {
            if (s[i] < s[i + 1]) {
                dip = i;
                break;
            }
        }
        
        if (dip == -1) {
            reverse(s.begin(), s.end());
            return s;
        }
        
        for (int i = n - 1; i >=0 ; i--) {
            if (s[i] > s[dip]) {
                swap(s[i], s[dip]);
                break;
            }
        }
        
        reverse(s.begin() + dip + 1, s.end());
        return s;
    }
};