class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.length(), l2 = s2.length();
        
        if (l1 > l2) return false;
        
        vector<int> s1Freq(26), s2Freq(26);
        
        for (char ch : s1) s1Freq[ch - 'a']++;
        
        for (int i = 0; i < l1; i++) s2Freq[s2[i] - 'a']++;
        
        if (s1Freq == s2Freq) return true;
        
        for (int i = l1; i < l2; i++) {
            s2Freq[s2[i - l1] - 'a']--;
            s2Freq[s2[i] - 'a']++;
            if (s1Freq == s2Freq) return true;
        }
        
        return false;
    }
};