class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int numStrings = strs.size();
        int stringLen = strs[0].length(); // all the strings are of same length
        
        int res = 0;
            
        for (int j = 0; j < stringLen; j++) {
            for (int i = 0; i < numStrings - 1; i++) {
                if(strs[i + 1][j] < strs[i][j]) {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};