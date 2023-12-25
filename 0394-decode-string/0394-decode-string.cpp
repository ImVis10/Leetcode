class Solution {
public:
    string decodeString(string s) {
        int idx = 0;
        return recurse(s, idx);
    }
private:
    string recurse(string& s, int& idx) {
        string res;
        while (idx < s.length() and s[idx] != ']') {
            if (!isdigit(s[idx])) res += s[idx++];
            else {
                int freq = 0;
                while (idx < s.length() and isdigit(s[idx])) {
                    freq = freq * 10 + (s[idx++] - '0');
                }
                idx++; // ignore [
                string decodedString = recurse(s, idx);
                idx++; // ignore ]
                while (freq--) {
                    res += decodedString;
                }
            }
        }
        return res;
    }
};