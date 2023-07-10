class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        /** so the question translates into
        FINDING MAXIMUM SUBSTRING OF 'T' with atmost k 'F' or FINDING MAXIMUM SUBSTRING OF 'F' with atmost k 'T'**/ 
        int n = answerKey.length();
        int numT = 0, numF = 0;
        int res = 0;
        
        for (int i = 0, j = 0; j < n; j++) { // i --> windowsStart, j --> windowEnd
            if (answerKey[j] == 'T') {
                numT++;
            } else {
                numF++;
            }
            
            while (min(numT, numF) > k) { // slide the window as long as min(numT, numF) exceeds k
                if (answerKey[i] == 'T') {
                    numT--;
                } else {
                    numF--;
                }
                i++;
            }
            
            res = max(res, j - i + 1);
        }
        return res;
    }
};