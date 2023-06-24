class Solution {
public:
    void reverseString(vector<char>& s) {
        rev(0, s.size() - 1, s);
    }
    
private:
    void rev(int l, int r, vector<char>& s) {
        if (l >= r) {
            return;
        }
        swap(s[l], s[r]);
        rev(l + 1, r - 1, s);
    }
};