class Solution {
public:
    int countGoodSubstrings(string s) {
        set<char> set;
        int count = 0;
        int j = 0, i = 0;
        while (j < s.length()) {
            set.insert(s[j]);
            if (j - i + 1 == 3) {
                if (set.size() == 3) {
                    count++;
                }
                set.clear();
                i++;
                j = i;
                continue;
            }
            j++;
        }
        set.clear();
        return count;
    }
};