class Solution {
public:
    int findTheLongestSubstring(string s) {
        // we do not need the count of each vowel
        // we just need to know if the count is odd or even
        // we can use bitmask for that
        // 5 bits to track parity, so 2^5 = 32 possible states
        
        unordered_map<char, int> vowels;
        vowels['a'] = 1;
        vowels['e'] = 2;
        vowels['i'] = 4;
        vowels['o'] = 8;
        vowels['u'] = 16;
        
        int res = 0, mask = 0;
        vector<int> maskToIdx(32, -1);
        
        for (int i = 0; i < s.length(); i++) {
            if (vowels.count(s[i])) {
                mask ^= vowels[s[i]]; 
            }
            
            if (maskToIdx[mask] != -1 or mask == 0) {
                int subStrLen = i - maskToIdx[mask];
                res = max(res, subStrLen);
            } else {
                maskToIdx[mask] = i;
            }
        }
        return res;
    }
};