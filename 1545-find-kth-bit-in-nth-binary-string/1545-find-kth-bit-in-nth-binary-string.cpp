class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        recur(n, s, k);
        return s[k - 1];
    }
private:
    void recur(int n, string& s, int k) {
        if (n == 0 or k == 1) return;
        string s1 = invert(s);
        reverse(s1.begin(), s1.end());
        s += "1" + s1;
        recur(n - 1, s, k - 1);
    }
private:
    string invert(string& s) {
        string s1 = s;
        for (char& ch : s1) {
            ch ^= 1;
        }
        return s1;
    }
};