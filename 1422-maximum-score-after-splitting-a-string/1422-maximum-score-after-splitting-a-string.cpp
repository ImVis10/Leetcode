class Solution {
public:
    int maxScore(string s) {
        int n = s.length(), res = 0;
        
        char one  = '1';
        
        auto countOnes = [one](const string& s) {
            return count(s.begin(), s.end(), one);
        };
        
        int numZeros = 0, numOnes = countOnes(s);
        
        for (int i = 0; i < n - 1; i++) { // < n - 1 as we need to have atleast one char in the right substring
            if (s[i] == '1') numOnes -= 1;
            else numZeros += 1;
            res = max(res, numOnes + numZeros);
        }
        return res;
    }
};