class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size(), res = 0;
        int numOnesInPrevRow = getNumOnes(bank[0]);
        for (int i = 1; i < m; i++) {
            int numOnesInCurrRow = getNumOnes(bank[i]);
            if (numOnesInCurrRow > 0) {
                res += (numOnesInCurrRow * numOnesInPrevRow);
                numOnesInPrevRow = numOnesInCurrRow;
            }
        }
        return res;
    }
    
private:
    int getNumOnes(string& s) {
        char one = '1';
        int numOnes = count_if(s.begin(), s.end(), [one](char ch) {
            return ch == one;
        });
        return numOnes;
    }
};