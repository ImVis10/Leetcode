class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // // instead of counting consistent strings, we will count inconsistent strings.
        // // all strings - #inconsistent strings is our result
        // int n = words.size();
        // int res = n;
        // vector<int> chars(26);
        // for (char& ch : allowed) chars[ch - 'a'] = 1;
        // for (string& word : words) {
        //     for (char& ch : word) {
        //         if (chars[ch - 'a'] != 1) {
        //             res--;
        //             break;
        //         }
        //     }
        // }
        // return res;
        
        // leetcode discuss section solution with just O(1) SPACE
        // INSTEAD OF VECTOR AS A MAP, USING AN INTEGER AS A MAP
        // INTEGER HAS 32 BITS, WE HAVE 26 CHARS SO WE HAVE ENOUGH BITS FOR EACH CHAR
        // 1 bit set against the chars in allowed
        int mp = 0;
        int res = words.size();
        for (char& ch: allowed) {
            mp |= (1 << (ch -'a'));
        }
        
        for (string& word : words) {
            for (char& ch : word) {
                if ((mp & (1 << (ch - 'a'))) == 0) {
                    res--;
                    break;
                }
            }
        }
        return res;
    }
};