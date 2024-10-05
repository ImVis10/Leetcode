class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length(), len2 = s2.length();
        
        if (len1 > len2) return false;
        
        vector<int> s1Freq(26), s2Freq(26);
        
        for (char ch : s1) s1Freq[ch - 'a']++;
        
        for (int i = 0; i < len1; i++) s2Freq[s2[i] - 'a']++;
        
        if (s1Freq == s2Freq) return true;
        
        for (int i = len1; i < len2; i++) {
            s2Freq[s2[i - len1] - 'a']--;
            s2Freq[s2[i] - 'a']++;
            if (s1Freq == s2Freq) return true;
        }
        
        return false;
    }
};