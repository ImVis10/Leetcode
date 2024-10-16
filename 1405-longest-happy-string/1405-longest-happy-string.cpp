class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int maxLen = a + b + c;
        string res;
        
        int contA = 0, contB = 0, contC = 0;
        
        while (maxLen--) {
            if ((a >= b and a >= c and contA < 2) or (contB == 2 and a > 0) or (contC == 2 and a > 0)) {
                a--;
                res += 'a';
                contA++;
                contB = 0;
                contC = 0;
            } else if ((b >= a and b >= c and contB < 2) or (contA == 2 and b > 0) or (contC == 2 and b > 0)) {
                b--;
                res += 'b';
                contB++;
                contA = 0;
                contC = 0;
            } else if ((c >= a and c >= b and contC < 2) or (contA == 2 and c > 0) or (contB == 2 and c > 0)) {
                c--;
                res += 'c';
                contC++;
                contA = 0;
                contB = 0;
            }
        }
        return res;
    }
};