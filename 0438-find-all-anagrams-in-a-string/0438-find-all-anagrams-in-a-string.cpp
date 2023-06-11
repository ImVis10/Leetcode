class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // int n1 = s.length(), n2 = p.length();
        // sort(p.begin(), p.end());
        // vector<int> res;
        // int start = -1;
        // int i = 0;
        // while (i < n1) {
        //     string sub = s.substr(i, n2);
        //     sort(sub.begin(), sub.end());
        //     if (sub == p) {
        //         res.push_back(i);
        //     }
        //     i++;
        // }
        // return res;   
        
        int sLen = s.length();
        int pLen = p.length();
        
        if (sLen  < pLen) {
            return {};
        }
        
        vector<int> freqP(26, 0);
        vector<int> windowS(26, 0);
        
        // window starting from 0 until pLen
        for (int i = 0; i < pLen; i++) {
            freqP[p[i] - 'a']++;
            windowS[s[i] - 'a']++;
        }
        
        vector<int> res;
        if (freqP == windowS) { // if window starting from 0 until pLen is an anagram of P
            res.push_back(0);
        }
        
        for (int i = pLen; i < sLen; i++) { // window starting from pLen
            windowS[s[i - pLen] - 'a']--;
            windowS[s[i]- 'a']++;
            if (freqP == windowS) {
                res.push_back(i - pLen + 1);
            }
        }
        return res;
    }
};